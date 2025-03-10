#!/usr/bin/perl
use strict;
use warnings;

my $log_file = "config/logs/error.log";

if (-e $log_file) {
    open(my $fh, '<', $log_file) or die "Cannot open log file: $!";
    while (my $line = <$fh>) {
        if ($line =~ /error/i) {
            print "[ERROR] $line";
        } elsif ($line =~ /warning/i) {
            print "[WARNING] $line";
        } else {
            print "[INFO] $line";
        }
    }
    close($fh);
} else {
    print "Log file not found.\n";
}
