// This file is auto-generated, don't edit it. Thanks.

#include <alibabacloud/roa.hpp>
#include <alibabacloud/credential.hpp>
#include <alibabacloud/roautil.hpp>
#include <boost/any.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/throw_exception.hpp>
#include <darabonba/core.hpp>
#include <darabonba/util.hpp>
#include <iostream>
#include <map>

using namespace std;

using namespace Alibabacloud_ROA;

Alibabacloud_ROA::Client::Client(const shared_ptr<Config>& config) {
  if (Darabonba_Util::Client::isUnset(config)) {
    BOOST_THROW_EXCEPTION(Darabonba::Error(map<string, string>({
      {"code", "ParameterMissing"},
      {"message", "'config' can not be unset"}
    })));
  }
  Darabonba_Util::Client::validateModel(config);
  if (!Darabonba_Util::Client::empty(config->accessKeyId) && !Darabonba_Util::Client::empty(config->accessKeySecret)) {
    if (!Darabonba_Util::Client::empty(config->securityToken)) {
      config->type = make_shared<string>("sts");
    }
    else {
      config->type = make_shared<string>("access_key");
    }
    shared_ptr<Alibabacloud_Credential::Config> credentialConfig = make_shared<Alibabacloud_Credential::Config>(map<string, string>({
      {"accessKeyId", !config->accessKeyId ? string() : *config->accessKeyId},
      {"type", !config->type ? string() : *config->type},
      {"accessKeySecret", !config->accessKeySecret ? string() : *config->accessKeySecret},
      {"securityToken", !config->securityToken ? string() : *config->securityToken}
    }));
    _credential = make_shared<Alibabacloud_Credential::Client>(credentialConfig);
  }
  else if (!Darabonba_Util::Client::isUnset(config->credential)) {
    _credential = config->credential;
  }
  else {
    BOOST_THROW_EXCEPTION(Darabonba::Error(map<string, string>({
      {"code", "ParameterMissing"},
      {"message", "'accessKeyId' and 'accessKeySecret' or 'credential' can not be unset"}
    })));
  }
  _regionId = config->regionId;
  _protocol = config->protocol;
  _endpointHost = config->endpoint;
  _readTimeout = config->readTimeout;
  _connectTimeout = config->connectTimeout;
  _httpProxy = config->httpProxy;
  _httpsProxy = config->httpsProxy;
  _maxIdleConns = config->maxIdleConns;
};

map<string, boost::any> Alibabacloud_ROA::Client::doRequest(shared_ptr<string> version,
                                                            shared_ptr<string> protocol,
                                                            shared_ptr<string> method,
                                                            shared_ptr<string> authType,
                                                            shared_ptr<string> pathname,
                                                            shared_ptr<map<string, string>> query,
                                                            shared_ptr<map<string, string>> headers,
                                                            const boost::any &body,
                                                            shared_ptr<Darabonba_Util::RuntimeOptions> runtime) {
  runtime->validate();
  shared_ptr<map<string, boost::any>> runtime_ = make_shared<map<string, boost::any>>(map<string, boost::any>({
    {"timeouted", boost::any("retry")},
    {"readTimeout", boost::any(Darabonba_Util::Client::defaultNumber(runtime->readTimeout, _readTimeout))},
    {"connectTimeout", boost::any(Darabonba_Util::Client::defaultNumber(runtime->connectTimeout, _connectTimeout))},
    {"httpProxy", boost::any(Darabonba_Util::Client::defaultString(runtime->httpProxy, _httpProxy))},
    {"httpsProxy", boost::any(Darabonba_Util::Client::defaultString(runtime->httpsProxy, _httpsProxy))},
    {"noProxy", boost::any(Darabonba_Util::Client::defaultString(runtime->noProxy, _noProxy))},
    {"maxIdleConns", boost::any(Darabonba_Util::Client::defaultNumber(runtime->maxIdleConns, _maxIdleConns))},
    {"retry", boost::any(map<string, boost::any>({
      {"retryable", !runtime->autoretry ? boost::any() : boost::any(*runtime->autoretry)},
      {"maxAttempts", boost::any(Darabonba_Util::Client::defaultNumber(runtime->maxAttempts, make_shared<int>(3)))}
    }))},
    {"backoff", boost::any(map<string, boost::any>({
      {"policy", boost::any(Darabonba_Util::Client::defaultString(runtime->backoffPolicy, make_shared<string>("no")))},
      {"period", boost::any(Darabonba_Util::Client::defaultNumber(runtime->backoffPeriod, make_shared<int>(1)))}
    }))},
    {"ignoreSSL", !runtime->ignoreSSL ? boost::any() : boost::any(*runtime->ignoreSSL)}
  })
);
  shared_ptr<Darabonba::Request> _lastRequest;
  shared_ptr<std::exception> _lastException;
  shared_ptr<int> _now = make_shared<int>(0);
  shared_ptr<int> _retryTimes = make_shared<int>(0);
  while (Darabonba::Core::allowRetry(make_shared<boost::any>((*runtime_)["retry"]), _retryTimes, _now)) {
    if (*_retryTimes > 0) {
      shared_ptr<int> _backoffTime = make_shared<int>(Darabonba::Core::getBackoffTime(make_shared<boost::any>((*runtime_)["backoff"]), _retryTimes));
      if (*_backoffTime > 0) {
        Darabonba::Core::sleep(_backoffTime);
      }
    }
    _retryTimes = make_shared<int>(*_retryTimes + 1);
    try {
      shared_ptr<Darabonba::Request> request_ = make_shared<Darabonba::Request>();
      request_->protocol = Darabonba_Util::Client::defaultString(_protocol, protocol);
      request_->method = *method;
      request_->pathname = *pathname;
      request_->headers = Darabonba::Converter::merge(map<string, string>({
        {"date", Darabonba_Util::Client::getDateUTCString()},
        {"host", !_endpointHost ? string() : *_endpointHost},
        {"accept", "application/json"},
        {"x-acs-signature-nonce", Darabonba_Util::Client::getNonce()},
        {"x-acs-signature-method", "HMAC-SHA1"},
        {"x-acs-signature-version", "1.0"},
        {"x-acs-version", !version ? string() : *version},
        {"user-agent", Darabonba_Util::Client::getUserAgent(_userAgent)},
        // x-sdk-client': helper.DEFAULT_CLIENT
      }), !headers ? map<string, string>() : *headers);
      if (!Darabonba_Util::Client::isUnset(make_shared<boost::any>(body))) {
        request_->body = Darabonba::Converter::toStream(Darabonba_Util::Client::toJSONString(make_shared<boost::any>(body)));
        request_->headers.insert(pair<string, string>("content-type", "application/json; charset=utf-8"));
      }
      if (!Darabonba_Util::Client::isUnset(query)) {
        request_->query = *query;
      }
      if (!Darabonba_Util::Client::equalString(authType, make_shared<string>("Anonymous"))) {
        shared_ptr<string> accessKeyId = make_shared<string>(_credential->getAccessKeyId());
        shared_ptr<string> accessKeySecret = make_shared<string>(_credential->getAccessKeySecret());
        shared_ptr<string> securityToken = make_shared<string>(_credential->getSecurityToken());
        if (!Darabonba_Util::Client::empty(securityToken)) {
          request_->headers.insert(pair<string, string>("x-acs-accesskey-id", *accessKeyId));
          request_->headers.insert(pair<string, string>("x-acs-security-token", *securityToken));
        }
        shared_ptr<string> stringToSign = make_shared<string>(Alibabacloud_ROAUtil::Client::getStringToSign(request_));
        request_->headers.insert(pair<string, string>("authorization", string("acs " + *accessKeyId + ":" + Alibabacloud_ROAUtil::Client::getSignature(stringToSign, accessKeySecret) + "")));
      }
      _lastRequest = request_;
      shared_ptr<Darabonba::Response> response_ = make_shared<Darabonba::Response>(Darabonba::Core::doAction(request_, runtime_));
      if (Darabonba_Util::Client::equalNumber(make_shared<int>(response_->statusCode), make_shared<int>(204))) {
        return {
          {"headers", response_->headers}
        };
      }
      shared_ptr<boost::any> result = make_shared<boost::any>(Darabonba_Util::Client::readAsJSON(response_->body));
      if (Darabonba_Util::Client::is4xx(make_shared<int>(response_->statusCode)) || Darabonba_Util::Client::is5xx(make_shared<int>(response_->statusCode))) {
        shared_ptr<map<string, boost::any>> err = make_shared<map<string, boost::any>>(Darabonba_Util::Client::assertAsMap(result));
        BOOST_THROW_EXCEPTION(Darabonba::Error(map<string, boost::any>({
          {"code", boost::any(string("" + Darabonba::Converter::toString(Client::defaultAny(make_shared<boost::any>((*err)["Code"]), make_shared<boost::any>((*err)["code"]))) + ""))},
          {"message", boost::any(string("code: " + boost::lexical_cast<string>(response_->statusCode) + ", " + Darabonba::Converter::toString(Client::defaultAny(make_shared<boost::any>((*err)["Message"]), make_shared<boost::any>((*err)["message"]))) + " request id: " + Darabonba::Converter::toString(Client::defaultAny(make_shared<boost::any>((*err)["RequestId"]), make_shared<boost::any>((*err)["requestId"]))) + ""))},
          {"data", !err ? boost::any() : boost::any(*err)}
        })));
      }
      return {
        {"headers", boost::any(response_->headers)},
        {"body", !result ? boost::any() : boost::any(*result)}
      };
    }
    catch (std::exception &e) {
      if (Darabonba::Core::isRetryable(e)) {
        _lastException = make_shared<std::exception>(e);
        continue;
      }
      BOOST_THROW_EXCEPTION(e);
    }
  }
  BOOST_THROW_EXCEPTION(Darabonba::UnretryableError(_lastRequest, _lastException));
}

map<string, boost::any> Alibabacloud_ROA::Client::doRequestWithAction(shared_ptr<string> action,
                                                                      shared_ptr<string> version,
                                                                      shared_ptr<string> protocol,
                                                                      shared_ptr<string> method,
                                                                      shared_ptr<string> authType,
                                                                      shared_ptr<string> pathname,
                                                                      shared_ptr<map<string, string>> query,
                                                                      shared_ptr<map<string, string>> headers,
                                                                      const boost::any &body,
                                                                      shared_ptr<Darabonba_Util::RuntimeOptions> runtime) {
  runtime->validate();
  shared_ptr<map<string, boost::any>> runtime_ = make_shared<map<string, boost::any>>(map<string, boost::any>({
    {"timeouted", boost::any("retry")},
    {"readTimeout", boost::any(Darabonba_Util::Client::defaultNumber(runtime->readTimeout, _readTimeout))},
    {"connectTimeout", boost::any(Darabonba_Util::Client::defaultNumber(runtime->connectTimeout, _connectTimeout))},
    {"httpProxy", boost::any(Darabonba_Util::Client::defaultString(runtime->httpProxy, _httpProxy))},
    {"httpsProxy", boost::any(Darabonba_Util::Client::defaultString(runtime->httpsProxy, _httpsProxy))},
    {"noProxy", boost::any(Darabonba_Util::Client::defaultString(runtime->noProxy, _noProxy))},
    {"maxIdleConns", boost::any(Darabonba_Util::Client::defaultNumber(runtime->maxIdleConns, _maxIdleConns))},
    {"retry", boost::any(map<string, boost::any>({
      {"retryable", !runtime->autoretry ? boost::any() : boost::any(*runtime->autoretry)},
      {"maxAttempts", boost::any(Darabonba_Util::Client::defaultNumber(runtime->maxAttempts, make_shared<int>(3)))}
    }))},
    {"backoff", boost::any(map<string, boost::any>({
      {"policy", boost::any(Darabonba_Util::Client::defaultString(runtime->backoffPolicy, make_shared<string>("no")))},
      {"period", boost::any(Darabonba_Util::Client::defaultNumber(runtime->backoffPeriod, make_shared<int>(1)))}
    }))},
    {"ignoreSSL", !runtime->ignoreSSL ? boost::any() : boost::any(*runtime->ignoreSSL)}
  })
);
  shared_ptr<Darabonba::Request> _lastRequest;
  shared_ptr<std::exception> _lastException;
  shared_ptr<int> _now = make_shared<int>(0);
  shared_ptr<int> _retryTimes = make_shared<int>(0);
  while (Darabonba::Core::allowRetry(make_shared<boost::any>((*runtime_)["retry"]), _retryTimes, _now)) {
    if (*_retryTimes > 0) {
      shared_ptr<int> _backoffTime = make_shared<int>(Darabonba::Core::getBackoffTime(make_shared<boost::any>((*runtime_)["backoff"]), _retryTimes));
      if (*_backoffTime > 0) {
        Darabonba::Core::sleep(_backoffTime);
      }
    }
    _retryTimes = make_shared<int>(*_retryTimes + 1);
    try {
      shared_ptr<Darabonba::Request> request_ = make_shared<Darabonba::Request>();
      request_->protocol = Darabonba_Util::Client::defaultString(_protocol, protocol);
      request_->method = *method;
      request_->pathname = *pathname;
      request_->headers = Darabonba::Converter::merge(map<string, string>({
        {"date", Darabonba_Util::Client::getDateUTCString()},
        {"host", !_endpointHost ? string() : *_endpointHost},
        {"accept", "application/json"},
        {"x-acs-signature-nonce", Darabonba_Util::Client::getNonce()},
        {"x-acs-signature-method", "HMAC-SHA1"},
        {"x-acs-signature-version", "1.0"},
        {"x-acs-version", !version ? string() : *version},
        {"x-acs-action", !action ? string() : *action},
        {"user-agent", Darabonba_Util::Client::getUserAgent(_userAgent)},
        // x-sdk-client': helper.DEFAULT_CLIENT
      }), !headers ? map<string, string>() : *headers);
      if (!Darabonba_Util::Client::isUnset(make_shared<boost::any>(body))) {
        request_->body = Darabonba::Converter::toStream(Darabonba_Util::Client::toJSONString(make_shared<boost::any>(body)));
        request_->headers.insert(pair<string, string>("content-type", "application/json; charset=utf-8"));
      }
      if (!Darabonba_Util::Client::isUnset(query)) {
        request_->query = *query;
      }
      if (!Darabonba_Util::Client::equalString(authType, make_shared<string>("Anonymous"))) {
        shared_ptr<string> accessKeyId = make_shared<string>(_credential->getAccessKeyId());
        shared_ptr<string> accessKeySecret = make_shared<string>(_credential->getAccessKeySecret());
        shared_ptr<string> securityToken = make_shared<string>(_credential->getSecurityToken());
        if (!Darabonba_Util::Client::empty(securityToken)) {
          request_->headers.insert(pair<string, string>("x-acs-accesskey-id", *accessKeyId));
          request_->headers.insert(pair<string, string>("x-acs-security-token", *securityToken));
        }
        shared_ptr<string> stringToSign = make_shared<string>(Alibabacloud_ROAUtil::Client::getStringToSign(request_));
        request_->headers.insert(pair<string, string>("authorization", string("acs " + *accessKeyId + ":" + Alibabacloud_ROAUtil::Client::getSignature(stringToSign, accessKeySecret) + "")));
      }
      _lastRequest = request_;
      shared_ptr<Darabonba::Response> response_ = make_shared<Darabonba::Response>(Darabonba::Core::doAction(request_, runtime_));
      if (Darabonba_Util::Client::equalNumber(make_shared<int>(response_->statusCode), make_shared<int>(204))) {
        return {
          {"headers", response_->headers}
        };
      }
      shared_ptr<boost::any> result = make_shared<boost::any>(Darabonba_Util::Client::readAsJSON(response_->body));
      if (Darabonba_Util::Client::is4xx(make_shared<int>(response_->statusCode)) || Darabonba_Util::Client::is5xx(make_shared<int>(response_->statusCode))) {
        shared_ptr<map<string, boost::any>> err = make_shared<map<string, boost::any>>(Darabonba_Util::Client::assertAsMap(result));
        BOOST_THROW_EXCEPTION(Darabonba::Error(map<string, boost::any>({
          {"code", boost::any(string("" + Darabonba::Converter::toString(Client::defaultAny(make_shared<boost::any>((*err)["Code"]), make_shared<boost::any>((*err)["code"]))) + ""))},
          {"message", boost::any(string("code: " + boost::lexical_cast<string>(response_->statusCode) + ", " + Darabonba::Converter::toString(Client::defaultAny(make_shared<boost::any>((*err)["Message"]), make_shared<boost::any>((*err)["message"]))) + " request id: " + Darabonba::Converter::toString(Client::defaultAny(make_shared<boost::any>((*err)["RequestId"]), make_shared<boost::any>((*err)["requestId"]))) + ""))},
          {"data", !err ? boost::any() : boost::any(*err)}
        })));
      }
      return {
        {"headers", boost::any(response_->headers)},
        {"body", !result ? boost::any() : boost::any(*result)}
      };
    }
    catch (std::exception &e) {
      if (Darabonba::Core::isRetryable(e)) {
        _lastException = make_shared<std::exception>(e);
        continue;
      }
      BOOST_THROW_EXCEPTION(e);
    }
  }
  BOOST_THROW_EXCEPTION(Darabonba::UnretryableError(_lastRequest, _lastException));
}

map<string, boost::any> Alibabacloud_ROA::Client::doRequestWithForm(shared_ptr<string> version,
                                                                    shared_ptr<string> protocol,
                                                                    shared_ptr<string> method,
                                                                    shared_ptr<string> authType,
                                                                    shared_ptr<string> pathname,
                                                                    shared_ptr<map<string, string>> query,
                                                                    shared_ptr<map<string, string>> headers,
                                                                    shared_ptr<map<string, boost::any>> body,
                                                                    shared_ptr<Darabonba_Util::RuntimeOptions> runtime) {
  runtime->validate();
  shared_ptr<map<string, boost::any>> runtime_ = make_shared<map<string, boost::any>>(map<string, boost::any>({
    {"timeouted", boost::any("retry")},
    {"readTimeout", boost::any(Darabonba_Util::Client::defaultNumber(runtime->readTimeout, _readTimeout))},
    {"connectTimeout", boost::any(Darabonba_Util::Client::defaultNumber(runtime->connectTimeout, _connectTimeout))},
    {"httpProxy", boost::any(Darabonba_Util::Client::defaultString(runtime->httpProxy, _httpProxy))},
    {"httpsProxy", boost::any(Darabonba_Util::Client::defaultString(runtime->httpsProxy, _httpsProxy))},
    {"noProxy", boost::any(Darabonba_Util::Client::defaultString(runtime->noProxy, _noProxy))},
    {"maxIdleConns", boost::any(Darabonba_Util::Client::defaultNumber(runtime->maxIdleConns, _maxIdleConns))},
    {"retry", boost::any(map<string, boost::any>({
      {"retryable", !runtime->autoretry ? boost::any() : boost::any(*runtime->autoretry)},
      {"maxAttempts", boost::any(Darabonba_Util::Client::defaultNumber(runtime->maxAttempts, make_shared<int>(3)))}
    }))},
    {"backoff", boost::any(map<string, boost::any>({
      {"policy", boost::any(Darabonba_Util::Client::defaultString(runtime->backoffPolicy, make_shared<string>("no")))},
      {"period", boost::any(Darabonba_Util::Client::defaultNumber(runtime->backoffPeriod, make_shared<int>(1)))}
    }))},
    {"ignoreSSL", !runtime->ignoreSSL ? boost::any() : boost::any(*runtime->ignoreSSL)}
  })
);
  shared_ptr<Darabonba::Request> _lastRequest;
  shared_ptr<std::exception> _lastException;
  shared_ptr<int> _now = make_shared<int>(0);
  shared_ptr<int> _retryTimes = make_shared<int>(0);
  while (Darabonba::Core::allowRetry(make_shared<boost::any>((*runtime_)["retry"]), _retryTimes, _now)) {
    if (*_retryTimes > 0) {
      shared_ptr<int> _backoffTime = make_shared<int>(Darabonba::Core::getBackoffTime(make_shared<boost::any>((*runtime_)["backoff"]), _retryTimes));
      if (*_backoffTime > 0) {
        Darabonba::Core::sleep(_backoffTime);
      }
    }
    _retryTimes = make_shared<int>(*_retryTimes + 1);
    try {
      shared_ptr<Darabonba::Request> request_ = make_shared<Darabonba::Request>();
      request_->protocol = Darabonba_Util::Client::defaultString(_protocol, protocol);
      request_->method = *method;
      request_->pathname = *pathname;
      request_->headers = Darabonba::Converter::merge(map<string, string>({
        {"date", Darabonba_Util::Client::getDateUTCString()},
        {"host", !_endpointHost ? string() : *_endpointHost},
        {"accept", "application/json"},
        {"x-acs-signature-nonce", Darabonba_Util::Client::getNonce()},
        {"x-acs-signature-method", "HMAC-SHA1"},
        {"x-acs-signature-version", "1.0"},
        {"x-acs-version", !version ? string() : *version},
        {"user-agent", Darabonba_Util::Client::getUserAgent(_userAgent)},
        // x-sdk-client': helper.DEFAULT_CLIENT
      }), !headers ? map<string, string>() : *headers);
      if (!Darabonba_Util::Client::isUnset(body)) {
        request_->body = Darabonba::Converter::toStream(Alibabacloud_ROAUtil::Client::toForm(body));
        request_->headers.insert(pair<string, string>("content-type", "application/x-www-form-urlencoded"));
      }
      if (!Darabonba_Util::Client::isUnset(query)) {
        request_->query = *query;
      }
      if (!Darabonba_Util::Client::equalString(authType, make_shared<string>("Anonymous"))) {
        shared_ptr<string> accessKeyId = make_shared<string>(_credential->getAccessKeyId());
        shared_ptr<string> accessKeySecret = make_shared<string>(_credential->getAccessKeySecret());
        shared_ptr<string> securityToken = make_shared<string>(_credential->getSecurityToken());
        if (!Darabonba_Util::Client::empty(securityToken)) {
          request_->headers.insert(pair<string, string>("x-acs-accesskey-id", *accessKeyId));
          request_->headers.insert(pair<string, string>("x-acs-security-token", *securityToken));
        }
        shared_ptr<string> stringToSign = make_shared<string>(Alibabacloud_ROAUtil::Client::getStringToSign(request_));
        request_->headers.insert(pair<string, string>("authorization", string("acs " + *accessKeyId + ":" + Alibabacloud_ROAUtil::Client::getSignature(stringToSign, accessKeySecret) + "")));
      }
      _lastRequest = request_;
      shared_ptr<Darabonba::Response> response_ = make_shared<Darabonba::Response>(Darabonba::Core::doAction(request_, runtime_));
      if (Darabonba_Util::Client::equalNumber(make_shared<int>(response_->statusCode), make_shared<int>(204))) {
        return {
          {"headers", response_->headers}
        };
      }
      shared_ptr<boost::any> result = make_shared<boost::any>(Darabonba_Util::Client::readAsJSON(response_->body));
      if (Darabonba_Util::Client::is4xx(make_shared<int>(response_->statusCode)) || Darabonba_Util::Client::is5xx(make_shared<int>(response_->statusCode))) {
        shared_ptr<map<string, boost::any>> err = make_shared<map<string, boost::any>>(Darabonba_Util::Client::assertAsMap(result));
        BOOST_THROW_EXCEPTION(Darabonba::Error(map<string, boost::any>({
          {"code", boost::any(string("" + Darabonba::Converter::toString(Client::defaultAny(make_shared<boost::any>((*err)["Code"]), make_shared<boost::any>((*err)["code"]))) + ""))},
          {"message", boost::any(string("code: " + boost::lexical_cast<string>(response_->statusCode) + ", " + Darabonba::Converter::toString(Client::defaultAny(make_shared<boost::any>((*err)["Message"]), make_shared<boost::any>((*err)["message"]))) + " request id: " + Darabonba::Converter::toString(Client::defaultAny(make_shared<boost::any>((*err)["RequestId"]), make_shared<boost::any>((*err)["requestId"]))) + ""))},
          {"data", !err ? boost::any() : boost::any(*err)}
        })));
      }
      return {
        {"headers", boost::any(response_->headers)},
        {"body", !result ? boost::any() : boost::any(*result)}
      };
    }
    catch (std::exception &e) {
      if (Darabonba::Core::isRetryable(e)) {
        _lastException = make_shared<std::exception>(e);
        continue;
      }
      BOOST_THROW_EXCEPTION(e);
    }
  }
  BOOST_THROW_EXCEPTION(Darabonba::UnretryableError(_lastRequest, _lastException));
}

boost::any Alibabacloud_ROA::Client::defaultAny(const boost::any &inputValue, const boost::any &defaultValue) {
  if (Darabonba_Util::Client::isUnset(make_shared<boost::any>(inputValue))) {
    return defaultValue;
  }
  return inputValue;
}

void Alibabacloud_ROA::Client::checkConfig(shared_ptr<Config> config) {
  if (Darabonba_Util::Client::empty(_endpointRule) && Darabonba_Util::Client::empty(config->endpoint)) {
    BOOST_THROW_EXCEPTION(Darabonba::Error(map<string, string>({
      {"code", "ParameterMissing"},
      {"message", "'config.endpoint' can not be empty"}
    })));
  }
}

