#!/usr/bin/env ruby

require 'optparse'
opt = OptionParser.new

dataNum = 10
startNum = 1
rangeNum = 10000
fileOut = "reference.txt"
sortEnable = false

opt.on('--dataNum NUM') {|v| dataNum = v.to_i }
opt.on('--startNum NUM') {|v| startNum = v.to_i }
opt.on('--rangeNum NUM') {|v| rangeNum = v.to_i }
opt.on('--fileOut STRING') {|v| fileOut = v }
opt.on('--sortEnable') {|v| sortEnable = true}

opt.parse!(ARGV)

File.open(fileOut, "w") {|dst|
  dst.puts("#{dataNum} #{startNum} #{rangeNum}")
  array = Array.new
  ##  set array  ##
  dataNum.times{|i|
    array.push(rand(rangeNum) + startNum)
  }
  array.sort! if(sortEnable)
  ##  print array  ##
  dataNum.times{|i|
    dst.puts(array[i])
  }
}
