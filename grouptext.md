#グループワークメモ
## 発表内容
- C11セキュリティライブラリについて説明する
- 代表的なものをピックアップして検証する
  - 各メンバーがセキュア関数を使った場合と使っていない場合の差を検証する
- 追試ができるように環境の構築手順をまとめる
  - 追試が簡単にできるように環境構築済みのVagrant boxを提供する

## 環境構築
- 別途用意した環境構築手順をもとに検証環境を作成する
  - サンプルコードをもとに動作確認を行い確かに検証できることをチェックした
- 検証環境をVagrantで作成しアップした(更新はすべて反映する予定)
  - 名称：aiit-alpha-team/CentOS-7.5_2018_SecurePrograming_group2 
  - URL：https://app.vagrantup.com/aiit-alpha-team/boxes/CentOS-7.5_2018_SecurePrograming_group2/versions/1.0.3 
  - なおメンバーは各自で構築した環境を使用しておりこのvoxは一名のみ使用している
- git-hub
  - 作業用のリポジトリを用意した
  - メンバーのローカル環境で作業できるところまで確認した

## C11について
- C11とはC言語の2011年度のバージョンで脆弱性への対策が行われている。
- この中には37種類のバッファオーバーフロー対策の行われた関数が導入された。
- これらの関数はデータの入力前に領域にデータが格納できるかどうかのチェックを行い、データが入りきらなければエラーとなる。
- エラー時の動作の内訳は下記の通り
    - エラーとして扱われる：29関数
    - 切り詰めて転記して正常終了：5関数
    - 一切書き込みせずに正常終了：1関数
    - 読み出しの関数でありスキャン範囲に上限がある：2関数

## 参照サイト
- 第10章 著名な脆弱性対策 C11：2011年以降のC言語仕様
  - https://www.ipa.go.jp/security/awareness/vendor/programmingv2/contents/c910.html
  - このサイトの内容をまとめ、さらに関数の実際の動作を確認して発表する

## 関数の対応
- 参考サイトから抜粋
    - C11の仕様－脆弱性対応に関連する機能強化点
    - https://www.buildinsider.net/language/clang/02
- C99とC11における関数の対応
- gets関数
    - gets_s関数
- getenv関数
    - getenv_s関数
- moment関数
    - moment_s関数
- tmpnam関数
    - tmpnam_s関数
    - tmpfile_s関数
- printf関数
    - printf_S関数


## 参考サイト
- C11の仕様－脆弱性対応に関連する機能強化点
    - https://www.buildinsider.net/language/clang/02
- Overview of various libc's regarding the secure C11 extensions
    - https://rurban.github.io/safeclib/doc/safec-3.3/d1/dae/md_doc_libc-overview.html
