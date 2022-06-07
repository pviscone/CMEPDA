#! /bin/bash
rm ./muonID5000.root
./sim run.mac
hadd muonID5000.root ./output*.root
rm ./output*.root