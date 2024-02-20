# stock_price_fetcher
ex for c programming  class
## stock_price_fetcher.cの作成と実行
```
//stock_price_fetcher.c
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
            curl_easy_setopt(curl, CURLOPT_URL, "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=IBM&apikey=YOUR_API_KEY");
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

```
1. libcurlのインストール

libcurlはC言語で書かれたライブラリで、HTTPリクエストを簡単に扱うことができます。このライブラリを使用するには、システムにインストールしておく必要があります。Ubuntuでは、次のコマンドを実行してlibcurlとその開発ファイルをインストールします。

```
sudo apt-get update
sudo apt-get install libcurl4-openssl-dev

```
2.unistd.hの使用

unistd.hはUNIX系システムの標準ヘッダーファイルで、標準入出力、ファイル操作、プロセス管理などの基本的なシステムコールを提供します。Ubuntuを含むほとんどのUNIX系OSでは、unistd.hは標準でインストールされているため、追加で行う必要のある作業はありません。

3.コードのコンパイル

```
gcc -o stock_price_fetcher stock_price_fetcher.c -lcurl

```
## tracerouteで接続先までのルートを確認したいとき
tracerouteのインストール
```
sudo apt-get update
sudo apt-get install traceroute
```
実行コマンド`traceroute www.alphavantage.co`

## APIキーを隠すには（githubの場合）
1. .envファイルを作成する
プロジェクトのルートディレクトリに.envファイルを作成する
```
API_KEY=your_api_key_here
```
2. .gitignoreファイルに追記する

プロジェクトのルートディレクトリに.gitignoreファイルを作成します。
.gitignoreファイルに.envファイルを追加して、Gitの追跡対象から除外します。ファイルの内容は以下のようになります：
```
.env
```

3.load_env.shスクリプトの作成

```
#!/bin/bash
export $(grep -v '^#' .env | xargs)
```
4.load_env.shの実行権限を設定して実行する
ターミナルで以下のコマンドを実行し、load_env.shに実行権限を付与します。
```
chmod +x load_env.sh
./load_env.sh
```

この方法で環境変数を設定すると、load_env.shを実行したシェルセッション内でのみ環境変数が利用可能になります。新しいターミナルやシェルセッションを開くと、再度load_env.shを実行する必要があります。
環境変数はセッション間で共有されないため、セキュリティの観点からも安全な方法です。ただし、.envファイルやスクリプトファイルに機密情報を含む場合は、これらのファイルのアクセス権を適切に管理し、無関係なユーザーからアクセスできないようにすることが重要です。
