#!/bin/bash

# 生成文件名
OUTPUT_FILE="1.txt"

# 目标大小（30MB）
TARGET_SIZE=$((30 * 1024 * 1024))  # 30 × 1024 × 1024 = 31457280 bytes

echo "⏳ Generating a 30MB text file..."

# 使用 /dev/urandom 生成随机内容（A-Z, a-z, 0-9），并限制大小
base64 /dev/urandom | head -c $TARGET_SIZE > "$OUTPUT_FILE"

echo "✅ Done! File created: $OUTPUT_FILE"
ls -lh "$OUTPUT_FILE"
