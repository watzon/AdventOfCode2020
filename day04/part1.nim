import re
import strutils
import algorithm
import strformat

const required_fields = [
  "byr",
  "ecl",
  "eyr",
  "hcl",
  "hgt",
  "iyr",
  "pid"
]

proc validate_passport(txt: string): bool =
  let pairs = re.split(txt, re"\s+")
  var fields = newSeq[string](0)

  for pair in pairs:
    let parts = pair.split(':')
    let key: string = cast[string](parts[0])
    if key != "cid":
      fields.add(key)

  fields.sort()
  return fields == required_fields

var count = 0
var backlog = newSeq[string](0)
let input = readFile("./input.txt")
let lines = input.split('\n')

for line in lines:
  if line.isEmptyOrWhitespace():
    let passport = backlog.join(" ")
    if validate_passport(passport):
      count += 1
    backlog.setLen(0)
  else:
    backlog.add(line)

echo(fmt"Valid passports: {count}")
