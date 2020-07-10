from unittest import TestCase

from alibabacloud_tea_roa.client import Client
from alibabacloud_tea_roa.models import Config

from alibabacloud_tea_util.models import RuntimeOptions

from Tea.exceptions import TeaException, UnretryableException

import threading
from http.server import HTTPServer, BaseHTTPRequestHandler


class Request(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header('Content-type', 'application/json')
        self.end_headers()
        self.wfile.write(b'{"result": "server test"}')

    def do_POST(self):
        self.path = '/pathname'
        self.send_response(400)
        self.send_header('Content-type', 'application/json')
        self.end_headers()
        self.wfile.write(b'{"result": "server error"}')


def run_server():
    server = HTTPServer(('localhost', 8888), Request)
    server.serve_forever()


class TestClient(TestCase):
    @classmethod
    def setUpClass(cls):
        server = threading.Thread(target=run_server)
        server.setDaemon(True)
        server.start()

    def test_init(self):
        conf = Config()
        try:
            Client(conf)
        except Exception as e:
            self.assertIsInstance(e, TeaException)
            self.assertEqual("""{'code': 'ParameterMissing', 'message': "'accessKeyId' and 'accessKeySecret' """ +
                             """or 'credential' can not be unset"}""", str(e))

        conf = Config(
            access_key_id='access_key_id',
            security_token='security_token',
            protocol='protocol',
            region_id='region_id',
            read_timeout=1000,
            connect_timeout=5000,
            http_proxy='http_proxy',
            https_proxy='https_proxy',
            endpoint='endpoint',
            no_proxy='no_proxy',
            max_idle_conns=1,
            network='network',
            suffix='suffix',
            type='type',
        )
        conf.access_key_secret = 'access_key_secret'
        client = Client(conf)
        self.assertIsNotNone(client)

    def test_do_request(self):
        conf = Config(
            access_key_id='access_key_id',
            security_token='security_token',
            protocol='http',
            region_id='region_id',
            read_timeout=10000,
            connect_timeout=5000,
            endpoint='127.0.0.1:8888',
            max_idle_conns=1
        )
        conf.access_key_secret = 'access_key_secret'
        runtime = RuntimeOptions(
            autoretry=False,
            max_attempts=2
        )
        client = Client(conf)
        res = client.do_request(
            protocol='http',
            method='GET',
            version='version',
            auth_type='auth_type',
            pathname='',
            query={},
            body=None,
            headers={},
            runtime=runtime
        )
        res.pop('headers')
        self.assertEqual({'body': {'result': 'server test'}}, res)
        try:
            client.do_request(
                protocol='http',
                method='POST',
                version='version',
                auth_type='auth_type',
                pathname='',
                query={},
                body=None,
                headers={},
                runtime=runtime
            )
        except Exception as e:
            self.assertIsInstance(e, UnretryableException)
