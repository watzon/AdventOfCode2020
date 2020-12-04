TREE = '#'
VECTORS = [
    [1, 1],
    [3, 1],
    [5, 1],
    [7, 1],
    [1, 2]
]

lines = File.read_lines("input.txt")
total = 1

VECTORS.each do |vec|
    trees_hit = 0
    pos = 0

    lines.each_with_index do |line, i|
        break if line.empty?
        next if i % vec[1] != 0

        if line[pos] == TREE
            trees_hit += 1
        end

        pos += vec[0]
        if pos + 1 > line.size
            pos = (pos - 1) - (line.size - 1)
        end
    end

    total *= trees_hit
    puts "Left #{vec[0]}, Down #{vec[1]} - #{trees_hit}"
end

puts "Answer: #{total}"
