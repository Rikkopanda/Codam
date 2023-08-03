#!/usr/bin/perl
use warnings;
use strict;

# Read grid size ('x' and 'y') and density ('density') from standard input
my $input_line = <STDIN>;
chomp $input_line;
my ($x, $y) = $input_line =~ /^\s*(\d+)\s+(\d+)\s*$/;

$input_line = <STDIN>;
chomp $input_line;
my $density = $input_line;

# Check if the input is valid
die "Invalid input: grid size and density must be positive integers\n" unless (defined $x && defined $y && $x > 0 && $y > 0 && $density =~ /^\d+$/ && $density <= 100);

my $grid_string = "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
        if (int(rand(100) + 1) <= $density) {
            $grid_string .= "o";
        } else {
            $grid_string .= ".";
        }
    }
    $grid_string .= "\n";
}

print $grid_string;  # Print the grid to stdout