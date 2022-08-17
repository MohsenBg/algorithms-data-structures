#!/bin/bash
count_arg=$#

TEST_TYPE=("ALL" "BINARY TREE" "GRAPH" "HASH TABLE" "LINK LIST" "SORTING")
TEST_LEN=${#TEST_TYPE[@]}

if [ $count_arg -lt 1 ]
  then
      echo -e " number\t |   Description"
      echo "----------------------------"
      for ((i = 0; i < $TEST_LEN; i++)); do 
          echo -e "    $i \t |   ${TEST_TYPE[$i]}"
      done

      printf "\nchoose test number:"
      read type
    else
      type=$1

fi
   if [[ $((type)) != $type ]]; then
    echo "only number!"
    exit 1
fi

if [ $type -gt $TEST_LEN ] || [ $type -lt 0 ];then
    echo "invalid test number"
    exit 2
fi

currentType=${TEST_TYPE[$type]}

# All
if [ "$currentType" == "${TEST_TYPE[0]}" ];then
  cargo test -- --test-threads=1

# Binary Tree
elif [ "$currentType" == "${TEST_TYPE[1]}" ];then
  echo ${TEST_TYPE[1]}

# Graph
elif [ "$currentType" == "${TEST_TYPE[2]}" ];then
   cargo test graph -- --test-threads=1 

# Hash Table
 elif [ "$currentType" == "${TEST_TYPE[3]}" ];then
  echo ${TEST_TYPE[3]}

# Link List
elif [ "$currentType" == "${TEST_TYPE[4]}" ];then
   cargo test link_list -- --test-threads=1
 
# Sort
elif [ "$currentType" == "${TEST_TYPE[5]}" ];then
  cargo test sort -- --test-threads=1

 fi

