#グループワークメモ
## 発表内容
- C11セキュリティライブラリについて説明する
- 代表的なものをピックアップして検証する
  - 各メンバーがセキュア関数を使った場合と使っていない場合の差を検証する
- 追試ができるように環境の構築手順をまとめる
  - 追試が簡単にできるように環境構築済みのVagrant boxを提供する

## 環境構築
### 環境構築の概要
- 別途用意した環境構築手順をもとに検証環境を作成する
  - サンプルコードをもとに動作確認を行い確かに検証できることをチェックした
- 検証環境をVagrantで作成しアップした(更新はすべて反映する予定)
  - 名称：aiit-alpha-team/CentOS-7.5_2018_SecurePrograming_group2 
  - URL：https://app.vagrantup.com/aiit-alpha-team/boxes/CentOS-7.5_2018_SecurePrograming_group2/versions/1.0.3 
  - なおメンバーは各自で構築した環境を使用しておりこのvoxは一名のみ使用している
- git-hub
  - 作業用のリポジトリを用意した
  - メンバーのローカル環境で作業できるところまで確認した

### 環境の構築手順
- 準備
  - sudo yum install gcc gcc-devel git autoconf automake libtool
- safclibインストール
  - sudo git clone https://github.com/rurban/safeclib.git
  - cd safeclib
  - ./build-tools/autogen.sh
  - ./configure
  - make
  - sudo make install

### コードのコンパイル手順と注意事項
- コンパイル手順(gets_s_example.cをコンパイルする場合)
  - gcc -std=c11 -c gets_s_example.c
  - gcc -o gets_s_example gets_s_example.o /usr/local/lib/libsafec-3.3.a
- 注意事項
　- コードの最上段で必ずinclude fileを指定する
  - 「#include “libsafec/safe_lib.h”」「#include “libsafec/safe_str_lib.h”」
　- これらが入力されていない場合はエラーになり実行できない
i

## C11について
- C11とはC言語の2011年度のバージョンで脆弱性への対策が行われている。
- この中には37種類のバッファオーバーフロー対策の行われた関数が導入された。
- 言語仕様そのものへの変更よりは、ライブラリ(関数)の変更が主である。
- これらの関数はデータの入力前に領域にデータが格納できるかどうかのチェックを行い、データが入りきらなければエラーとなる。
- エラー時の動作の内訳は下記の通り
    - エラーとして扱われる：29関数
    - 切り詰めて転記して正常終了：5関数
    - 一切書き込みせずに正常終了：1関数
    - 読み出しの関数でありスキャン範囲に上限がある：2関数
- C11はまだ規格化されて間もないため処理系によるサポートはこれから進んでいくものと思われる。
- 今回紹介する機能の多くはC11仕様のAnnex Kで定められているものであり、これらは実装がオプション扱いとなっている。


## ライブラリの紹介
- ライブラリ名：Safe C Library
- https://github.com/rurban/safeclib
- ライブラリを導入することで、標準のC11には搭載されていない下記のような安全な関数を利用することができる
- bsearch_s, fscanf_s, fwscanf_s, gets_s, gmtime_s, localtime_s,scanf_s, sscanf_s,swscanf_s, strtok_s, vfscanf_s, vfwscanf_s, vsscanf_s, vswscanf_s, wcstok_s, wscanf_s. その他

## 検証時に参考にしたサイト
- 第10章 著名な脆弱性対策 C11：2011年以降のC言語仕様
  - https://www.ipa.go.jp/security/awareness/vendor/programmingv2/contents/c910.html
  - このサイトの内容をまとめ、さらに関数の実際の動作を確認して発表する

### 関数の対応
- 参考サイトから抜粋
    - C11の仕様－脆弱性対応に関連する機能強化点
    - https://www.buildinsider.net/language/clang/02
- C99とC11における関数の対応
- gets関数 (Wが担当)
    - gets_s関数
- getenv関数 (Fが担当)
    - getenv_s関数
- moment関数
    - moment_s関数
- tmpnam関数
    - tmpnam_s関数
    - tmpfile_s関数
- printf関数 (Kが担当)
    - printf_s関数

## サンプルコードの実行と結果 
### getenv_S関数の説明
- 担当：F

### gets_s関数の説明
- 担当：W

### printf_s関数の説明
- 担当：K


## C11で追加された関数のリスト
- abort_handler_s
- asctime_s
- bsearch_s
- ctime_s
- fopen_s
- fprintf_s
- freopen_s
- fscanf_s
- fwprintf_s
- fwscanf_s
- getenv_s
- gets_s
- gmtime_s
- hangul
- ignore_handler_s
- localtime_s
- mbsrtowcs_s
- mbstowcs_s
- mem_primitives_lib
- memccpy_s
- memchr_s
- memcmp16_s
- memcmp32_s
- memcmp_s
- memcpy16_s
- memcpy32_s
- memcpy_s
- memmove16_s
- memmove32_s
- memmove_s
- memrchr_s
- memset16_s
- memset32_s
- memset_s
- memzero16_s
- memzero32_s
- memzero_s
- printf_s
- qsort_s
- safe_compile
- safe_config
- safe_lib
- safe_lib_errno
- safe_mem_constraint
- safe_mem_lib
- safe_str_constraint
- safe_str_lib
- safe_types
- scanf_s
- slkm_init
- snprintf_s
- snwprintf_s
- sprintf_s
- sscanf_s
- strcasecmp_s
- strcasestr_s
- strcat_s
- strchr_s
- strcmp_s
- strcmpfld_s
- strcoll_s
- strcpy_s
- strcpyfld_s
- strcpyfldin_s.c
- strcpyfldout_s.c
- strcspn_s
- strerror_s
- strfirstchar_s
- strfirstdiff_s
- strfirstsame_s
- strisalphanumeric_s
- strisascii_s
- strisdigit_s
- strishex_s
- strislowercase_s
- strismixedcase_s
- strispassword_s
- strisuppercase_s
- strlastchar_s
- strlastdiff_s
- strlastsame_s
- strljustify_s
- strnatcmp_s
- strncat_s
- strncpy_s
- strnlen_s
- strnset_s
- strnterminate_s
- strpbrk_s
- strprefix_s
- strrchr_s
- strremovews_s
- strset_s
- strspn_s
- strstr_s
- strtok_s
- strtolowercase_s
- strtouppercase_s
- strzero_s
- swprintf_s
- swscanf_s	
- timingsafe_bcmp
- timingsafe_memcmp
- tmpfile_s
- tmpnam_s
- towctrans
- towfc_s
- unw16ifcan
- unw16ifcm
- unw16ifcmp
- unw16ifcpt
- unw16ifexc
- unwifcan
- unwifcmb
- unwifcmp
- unwifcpt
- unwifexc
- vfprintf_s
- vfscanf_s
- vfwprintf_s
- vfwscanf_s
- vprintf_s
- vscanf_s
- vsnprintf_s
- vsnwprintf_s
- vsprintf_s
- vsscanf_s.
- vswprintf_s
- vswscanf_s
- vwprintf_s
- vwscanf_s
- wcrtomb_s
- wcscat_s
- wcscmp_s
- wcscoll_s
- wcscpy_s
- wcsfc_s
- wcsicmp_s
- wcslwr_s
- wcsnatcmp_s
- wcsncat_s
- wcsncmp_s
- wcsncpy_s
- wcsnlen_s
- wcsnorm_s
- wcsnset_s
- wcsrtombs_s
- wcsset_s
- wcsstr
- wcsstr_s
- wcstok_s
- wcstombs_s
- wcsupr_s
- wctomb_s
- wmemcmp_s
- wmemcpy_s
- wmemmove_s
- wprintf_s
- wscanf_s

## 参考サイト
- C11の仕様－脆弱性対応に関連する機能強化点
    - https://www.buildinsider.net/language/clang/02
- Overview of various libc's regarding the secure C11 extensions
    - https://rurban.github.io/safeclib/doc/safec-3.3/d1/dae/md_doc_libc-overview.html
- safec fork with all C11 Annex K functions 
    - https://github.com/rurban/safeclib
