
# =====================================================
#  Simple Makefile for 2D-GRHD project (C version)
# =====================================================

# コンパイラ
CC = gcc

# コンパイルオプション
CFLAGS = -O2 -Wall -Wextra -std=c17
OMPFLAGS = -fopenmp

# ソースコード
SRCS = main.c initval.c grid.c metric.c constant.c

# オブジェクトファイル
OBJS = $(SRCS:.c=.o)

# 実行ファイル名
TARGET = run

# =====================================================
# ルール定義
# =====================================================

# デフォルトターゲット
all: $(TARGET)

# リンク
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lm

# コンパイル
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# クリーンアップ
clean:
	rm -f $(OBJS) $(TARGET)

# デバッグビルド（必要なら）
debug: CFLAGS += -g -O0
debug: clean all

# OpenMP
omp: CFLAGS += $(OMPFLAGS)
omp: clean all
# =====================================================
# 補足メモ:
# make        → 通常ビルド
# make debug  → デバッグ用ビルド (-g付き)
# make clean  → 中間・実行ファイル削除
# =====================================================
