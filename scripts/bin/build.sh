#!/bin/bash
echo "Building project..."
exec "$(command -v make)" -j$(nproc)
