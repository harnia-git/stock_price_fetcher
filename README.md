# stock_price_fetcher
ex for c programming  class

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
4.tracerouteのインストール

```
sudo apt-get update
sudo apt-get install traceroute
traceroute www.alphavantage.co


```
