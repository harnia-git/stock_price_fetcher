#include <stdio.h>
#include <stdlib.h> // getenv関数を使うために必要
#include <curl/curl.h>
#include <unistd.h> // UNIX系OSの場合

size_t callback(void *contents, size_t size, size_t nmemb, void *userp) {
    printf("%s", (char*)contents);
    return size * nmemb;
}

int main(void) {
    CURL *curl;
    CURLcode res;
    char *apiKey = getenv("API_KEY"); // 環境変数からAPIキーを取得

    if(apiKey == NULL) {
        fprintf(stderr, "Error: API_KEY environment variable is not set.\n");
        return 1; // 環境変数が設定されていない場合はエラーを出力して終了
    }

    char url[256]; // URL文字列を格納するための配列
    snprintf(url, sizeof(url), "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=IBM&apikey=%s", apiKey);

    curl = curl_easy_init();
    if(curl) {
        while(1) { // 無限ループ
            curl_easy_setopt(curl, CURLOPT_URL, url);
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
