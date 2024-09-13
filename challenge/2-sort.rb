# Initialize an empty array to store sorted integers
result = []

# Iterate over each argument provided to the script
ARGV.each do |arg|
  # Skip if the argument is not an integer
  next unless arg =~ /^-?\d+$/

  # Convert the argument to an integer
  i_arg = arg.to_i

  # Insert the integer into the result array while maintaining order
  inserted = false
  result.each_with_index do |num, index|
    if i_arg < num
      result.insert(index, i_arg)
      inserted = true
      break
    end
  end

  # If the integer is larger than all elements in the array, append it at the end
  result.push(i_arg) unless inserted
end

# Print the sorted result array, joining elements with a space
puts result.join(" ")
