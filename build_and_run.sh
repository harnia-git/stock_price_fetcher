#!/bin/bash

# .envファイルから環境変数を読み込む
export $(grep -v '^#' .env | xargs)

# stock_price_fetcher.cをコンパイル
gcc -o stock_price_fetcher stock_price_fetcher.c -lcurl

# コンパイルが成功したら、実行ファイルを実行
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running stock_price_fetcher..."
    ./stock_price_fetcher
else
    echo "Compilation failed."
fi
