#!/usr/bin/env ruby

require 'optparse'
opt = OptionParser.new

dataNum = 10
startNum = 1
rangeNum = 10000
fileVect = "vector.txt"
fileExp = ""

opt.on('--dataNum NUM') {|v| dataNum = v.to_i }
opt.on('--startNum NUM') {|v| startNum = v.to_i }
opt.on('--rangeNum NUM') {|v| rangeNum = v.to_i }
opt.on('--fileVect STRING') {|v| fileVect = v }
opt.on('--fileExp STRING') {|v| fileExp = v }

opt.parse!(ARGV)

array = Array.new
##  set array  ##
dataNum.times{|i|
  array.push(rand(rangeNum) + startNum)
}

def writeArray(fname)
end

File.open(fileVect, "w") {|dst|
  dst.puts("#{dataNum} #{startNum} #{rangeNum}")
  ##  print array  ##
  dataNum.times{|i|
    dst.puts(array[i])
  }
}

exit if(fileExp.size < 1)
array.sort!

File.open(fileExp, "w") {|dst|
  dst.puts("#{dataNum} #{startNum} #{rangeNum}")
  ##  print array  ##
  dataNum.times{|i|
    dst.puts(array[i])
  }
}
