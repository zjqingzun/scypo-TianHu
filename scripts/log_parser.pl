#!/usr/bin/perl
use strict;
use warnings;

my $error_log = "logs/error.log";

# Kiểm tra nếu file tồn tại
if (!-e $error_log) {
    print "⚠️ Không tìm thấy $error_log\n";
    exit 1;
}

open(my $fh, '<', $error_log) or die "❌ Không thể mở $error_log: $!";

print "=== Phân tích lỗi ===\n";
while (my $line = <$fh>) {
    chomp $line;
    if ($line =~ /(error|warning)/i) {
        print "⚠️  $line\n";
    }
}

close($fh);
print "=== Hoàn tất phân tích ===\n";
