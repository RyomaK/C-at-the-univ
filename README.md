# C++

## cat command
### 内容
大学のC言語Ⅱ第7回講義
cat コマンドをc++で実装
### オプション
- n  
行数を表示する
- f[str]  
ファイル内に含まれるstrを検索し行数をと個数表示(自作）
一致した文字列を黄色で着色
### 使い方
g++ -Wall -std=c++11 cat_command.cpp  
./a.out file_name -n -f 検索文字列
