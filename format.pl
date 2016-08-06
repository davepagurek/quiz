#!/usr/bin/env perl6
use v6;

grammar Questions {
  token TOP { <title> <questions>+ }
  token questions { <grouptitle> <question>+ }
  token title { \V+  \n+ 'Chapter' \V+ \n+ }
  token grouptitle { \d+\.\d+ \V+ \n+ }
  proto token question {*}
  token question:sym<mc> {
    $<q>=[\d+')' \V+] \n+
    <option>+
    'Answer:' \s+ $<correct>=[\w] \n*
  }
  token question:sym<tf> {
    $<q>=[\d+')' \V+] \n+
    'Answer:' \s+ $<correct>=['TRUE' | 'FALSE'] \n*
  }
  token question:sym<sa> {
    $<q>=[\d+')' \V+] \n+
    'Answer:' \s+ [\S+\s+]+<?{ !($/ ~~ /'TRUE'|'FALSE'/)  }> \n*
  }
  token option { $<text>=[\w')' \V+] \n+ }
}

class Actions {
  method TOP($/) {
    #$/.make: "test";
    $/.make: $<questions>.map(*.made).join("");
  }
  method questions($/) {
    $/.make: $<question>.map(*.made).join("");
  }
  method question:sym<mc>($/) {
    if $<correct> ~~ 'E' {
      $/.make: "Question: Multiple Choice\n"
      ~ $<q> ~ "\n"
      ~ $<option>.head(3).map(*.Str).join("")
      ~ $<option>[4].subst('E)', 'D)')
      ~ "D\n";
    } else {
      $/.make: "Question: Multiple Choice\n"
      ~ $<q> ~ "\n"
      ~ $<option>.head(4).map(*.Str).join("")
      ~ $<correct> ~ "\n";
    }
  }
  method question:sym<tf>($/) {
    $/.make: "Question: True/False\n"
    ~ $<q> ~ "\n"
    ~ ($<correct> ~~ "TRUE" ?? "T" !! "F") ~ "\n";
  }
  method question:sym<sa>($/) { $/.make: ""; }
}

sub MAIN(Str $input, Str $output) {
  my $out = open $output, :w;
  $out.say: Questions.parse($input.IO.slurp, actions => Actions.new).made;
}
