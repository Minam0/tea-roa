// This file is auto-generated, don't edit it. Thanks.

#ifndef ALIBABACLOUD_ROA_H_
#define ALIBABACLOUD_ROA_H_

#include <alibabacloud/credential.hpp>
#include <alibabacloud/roautil.hpp>
#include <boost/any.hpp>
#include <darabonba/core.hpp>
#include <darabonba/util.hpp>
#include <iostream>
#include <map>

using namespace std;

namespace Alibabacloud_ROA {
class Config : public Darabonba::Model {
public:
  Config() {}
  explicit Config(const std::map<string, boost::any> &config) : Darabonba::Model(config) {
    fromMap(config);
  };

  void validate() override {
    Darabonba::Model::validatePattern("regionId", regionId, "^[a-zA-Z0-9_-]+$");
    Darabonba::Model::validatePattern("network", network, "^[a-zA-Z0-9_-]+$");
    Darabonba::Model::validatePattern("suffix", suffix, "^[a-zA-Z0-9_-]+$");
  }

  map<string, boost::any> toMap() override {
    map<string, boost::any> res;
    if (accessKeyId) {
      res["accessKeyId"] = boost::any(*accessKeyId);
    }
    if (accessKeySecret) {
      res["accessKeySecret"] = boost::any(*accessKeySecret);
    }
    if (securityToken) {
      res["securityToken"] = boost::any(*securityToken);
    }
    if (protocol) {
      res["protocol"] = boost::any(*protocol);
    }
    if (regionId) {
      res["regionId"] = boost::any(*regionId);
    }
    if (readTimeout) {
      res["readTimeout"] = boost::any(*readTimeout);
    }
    if (connectTimeout) {
      res["connectTimeout"] = boost::any(*connectTimeout);
    }
    if (httpProxy) {
      res["httpProxy"] = boost::any(*httpProxy);
    }
    if (httpsProxy) {
      res["httpsProxy"] = boost::any(*httpsProxy);
    }
    if (endpoint) {
      res["endpoint"] = boost::any(*endpoint);
    }
    if (noProxy) {
      res["noProxy"] = boost::any(*noProxy);
    }
    if (userAgent) {
      res["userAgent"] = boost::any(*userAgent);
    }
    if (maxIdleConns) {
      res["maxIdleConns"] = boost::any(*maxIdleConns);
    }
    if (network) {
      res["network"] = boost::any(*network);
    }
    if (suffix) {
      res["suffix"] = boost::any(*suffix);
    }
    if (type) {
      res["type"] = boost::any(*type);
    }
    return res;
  }

  void fromMap(map<string, boost::any> m) override {
    if (m.find("accessKeyId") != m.end()) {
      accessKeyId = make_shared<string>(boost::any_cast<string>(m["accessKeyId"]));
    }
    if (m.find("accessKeySecret") != m.end()) {
      accessKeySecret = make_shared<string>(boost::any_cast<string>(m["accessKeySecret"]));
    }
    if (m.find("securityToken") != m.end()) {
      securityToken = make_shared<string>(boost::any_cast<string>(m["securityToken"]));
    }
    if (m.find("protocol") != m.end()) {
      protocol = make_shared<string>(boost::any_cast<string>(m["protocol"]));
    }
    if (m.find("regionId") != m.end()) {
      regionId = make_shared<string>(boost::any_cast<string>(m["regionId"]));
    }
    if (m.find("readTimeout") != m.end()) {
      readTimeout = make_shared<int>(boost::any_cast<int>(m["readTimeout"]));
    }
    if (m.find("connectTimeout") != m.end()) {
      connectTimeout = make_shared<int>(boost::any_cast<int>(m["connectTimeout"]));
    }
    if (m.find("httpProxy") != m.end()) {
      httpProxy = make_shared<string>(boost::any_cast<string>(m["httpProxy"]));
    }
    if (m.find("httpsProxy") != m.end()) {
      httpsProxy = make_shared<string>(boost::any_cast<string>(m["httpsProxy"]));
    }
    if (m.find("endpoint") != m.end()) {
      endpoint = make_shared<string>(boost::any_cast<string>(m["endpoint"]));
    }
    if (m.find("noProxy") != m.end()) {
      noProxy = make_shared<string>(boost::any_cast<string>(m["noProxy"]));
    }
    if (m.find("userAgent") != m.end()) {
      userAgent = make_shared<string>(boost::any_cast<string>(m["userAgent"]));
    }
    if (m.find("maxIdleConns") != m.end()) {
      maxIdleConns = make_shared<int>(boost::any_cast<int>(m["maxIdleConns"]));
    }
    if (m.find("network") != m.end()) {
      network = make_shared<string>(boost::any_cast<string>(m["network"]));
    }
    if (m.find("suffix") != m.end()) {
      suffix = make_shared<string>(boost::any_cast<string>(m["suffix"]));
    }
    if (m.find("type") != m.end()) {
      type = make_shared<string>(boost::any_cast<string>(m["type"]));
    }
  }

  shared_ptr<string> accessKeyId{};
  shared_ptr<string> accessKeySecret{};
  shared_ptr<string> securityToken{};
  shared_ptr<string> protocol{};
  shared_ptr<string> regionId{};
  shared_ptr<int> readTimeout{};
  shared_ptr<int> connectTimeout{};
  shared_ptr<string> httpProxy{};
  shared_ptr<string> httpsProxy{};
  shared_ptr<Alibabacloud_Credential::Client> credential{};
  shared_ptr<string> endpoint{};
  shared_ptr<string> noProxy{};
  shared_ptr<string> userAgent{};
  shared_ptr<int> maxIdleConns{};
  shared_ptr<string> network{};
  shared_ptr<string> suffix{};
  shared_ptr<string> type{};

  ~Config() = default;
};
class Client {
public:
  shared_ptr<string> _protocol{};
  shared_ptr<int> _readTimeout{};
  shared_ptr<int> _connectTimeout{};
  shared_ptr<string> _httpProxy{};
  shared_ptr<string> _httpsProxy{};
  shared_ptr<string> _noProxy{};
  shared_ptr<int> _maxIdleConns{};
  shared_ptr<string> _endpointHost{};
  shared_ptr<string> _network{};
  shared_ptr<string> _endpointRule{};
  shared_ptr<map<string, string>> _endpointMap{};
  shared_ptr<string> _suffix{};
  shared_ptr<string> _productId{};
  shared_ptr<string> _regionId{};
  shared_ptr<string> _userAgent{};
  shared_ptr<Alibabacloud_Credential::Client> _credential{};
  explicit Client(const shared_ptr<Config>& config);
  map<string, boost::any> doRequest(shared_ptr<string> version,
                                    shared_ptr<string> protocol,
                                    shared_ptr<string> method,
                                    shared_ptr<string> authType,
                                    shared_ptr<string> pathname,
                                    shared_ptr<map<string, string>> query,
                                    shared_ptr<map<string, string>> headers,
                                    const boost::any &body,
                                    shared_ptr<Darabonba_Util::RuntimeOptions> runtime);
  map<string, boost::any> doRequestWithAction(shared_ptr<string> action,
                                              shared_ptr<string> version,
                                              shared_ptr<string> protocol,
                                              shared_ptr<string> method,
                                              shared_ptr<string> authType,
                                              shared_ptr<string> pathname,
                                              shared_ptr<map<string, string>> query,
                                              shared_ptr<map<string, string>> headers,
                                              const boost::any &body,
                                              shared_ptr<Darabonba_Util::RuntimeOptions> runtime);
  map<string, boost::any> doRequestWithForm(shared_ptr<string> version,
                                            shared_ptr<string> protocol,
                                            shared_ptr<string> method,
                                            shared_ptr<string> authType,
                                            shared_ptr<string> pathname,
                                            shared_ptr<map<string, string>> query,
                                            shared_ptr<map<string, string>> headers,
                                            shared_ptr<map<string, boost::any>> body,
                                            shared_ptr<Darabonba_Util::RuntimeOptions> runtime);
  static boost::any defaultAny(const boost::any &inputValue, const boost::any &defaultValue);
  void checkConfig(shared_ptr<Config> config);

  ~Client() = default;
};
} // namespace Alibabacloud_ROA

#endif