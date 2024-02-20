#include <stdio.h>
#include <curl/curl.h>
#include <unistd.h> // UNIX系OSの場合

size_t callback(void *contents, size_t size, size_t nmemb, void *userp) {
    printf("%s", (char*)contents);
    return size * nmemb;
}

int main(void) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        while(1) { // 無限ループ
            curl_easy_setopt(curl, CURLOPT_URL, "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=IBM&apikey=T6DJAJEHNGVGWM9N");
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
            res = curl_easy_perform(curl);

            if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

            sleep(5); // 5秒待機
        }
        curl_easy_cleanup(curl);
    }
    return 0;
}
