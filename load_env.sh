#!/bin/bash

# .envファイルから環境変数を読み込む
export $(grep -v '^#' .env | xargs)