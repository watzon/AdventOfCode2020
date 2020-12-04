TREE = '#'
lines = File.read_lines("input.txt")

trees_hit = 0
pos = 0

lines.each_with_index do |line, i|
    break if line.empty?

    if line[pos] == TREE
        trees_hit += 1
    end

    pos += 3
    if pos + 1 > line.size
        pos = (pos - 1) - (line.size - 1)
    end

    puts line
end

puts trees_hit
