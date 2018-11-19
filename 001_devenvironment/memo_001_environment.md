# セキュアプログラミング特論 検証環境メモ

## 検証環境
- 使用ツール
    - Vagrant 2.1.1
    - Oracle Virtual Box 5.2.12
- 検証環境
    - CentOS 7.5.1804

## 設定済みイメージ
- aiit-alpha-team/CentOS-7.5_2018_SecurePrograming_group2
    - https://app.vagrantup.com/aiit-alpha-team/boxes/CentOS-7.5_2018_SecurePrograming_group2

## 設定手順
### 初期設定
- cat /etc/redhat-release
- sudo yum update
- sudo yum install -y tree vim
- sudo vim /etc/vimrc
    - 最終行に以下を追記
    - set number
    - hi Comment ctermfg=gray

### C言語コンパイル環境の設定
- sudo yum install -y glibc-devel.i686 libgcc.i686 libstdc++-devel.i686 ncurses-devel.i686 prelink emacs
- sudo yum update

### C11ライブラリの設定
- sudo yum -y install git autoconf automake libtool
- git clone https://github.com/rurban/safeclib.git
- cd safeclib
- ./build-tools/autogen.sh
- ./configure
- make
- sudo make install

### 動作確認
- サンプルコードを実行して検証環境の構築ができていることを確認する
- サンプルコード：gets_s_example.c (当リポジトリ内に保存さてている)
- gcc -std=c11 -c gets_s_example.c
- gcc -o gets_s_example gets_s_example.o /usr/local/lib/libsafec-3.3.a

### safeclibを利用したい場合
- 以下のヘッダーファイルをincludeする
- include "libsafec/safe_lib.h"