#pragma once

#include <string>
#include <curl/curl.h>

namespace ignacionr {

    class cppslack {
    private:
        std::string webhook_url;

        bool send_post_request(const std::string& payload) const {
            CURL* curl;
            CURLcode res;

            curl = curl_easy_init();
            if(curl) {
                curl_easy_setopt(curl, CURLOPT_URL, webhook_url.c_str());
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());

                res = curl_easy_perform(curl);
                curl_easy_cleanup(curl);

                if(res != CURLE_OK) {
                    fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
                    return false;
                }
                return true;
            }
            return false;
        }

    public:
        cppslack(const std::string& url) : webhook_url(url) {}

        bool send_message(const std::string& message) const {
            std::string payload = "{\"text\": \"" + message + "\"}";
            return send_post_request(payload);
        }

        bool send_message(const std::string& message, const std::string& username) const {
            std::string payload = "{\"text\": \"" + message + "\", \"username\": \"" + username + "\"}";
            return send_post_request(payload);
        }

        bool send_message(const std::string& message, const std::string& username, const std::string& channel) const {
            std::string payload = "{\"text\": \"" + message + "\", \"username\": \"" + username + "\", \"channel\": \"" + channel + "\"}";
            return send_post_request(payload);
        }

        bool send_message_with_attachments(const std::string& message, const std::string& attachments) const {
            std::string payload = "{\"text\": \"" + message + "\", \"attachments\": " + attachments + "}";
            return send_post_request(payload);
        }
    };

} // namespace ignacionr
