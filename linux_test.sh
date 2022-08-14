#!/bin/bash
count_arg=$#

TEST_TYPE=("ALL" "BINARY TREE" "GRAPH" "HASH TABLE" "LINK LIST" "SORTING")
TEST_LEN=${#TEST_TYPE[@]}

if [ $count_arg -lt 1 ]
  then
      echo -e "   code\t |   Description"
      echo "----------------------------"
      for ((i = 0; i < $TEST_LEN; i++)); do 
          echo -e "    $i \t |   ${TEST_TYPE[$i]}"
      done

      printf "\nchoose Type_code:"
      read type
    else
      type=$1

fi
   if [[ $((type)) != $type ]]; then
    echo "only number!"
    exit 1
fi

if [ $type -gt $TEST_LEN ] || [ $type -lt 0 ];then
    echo "invalid Test number"
    exit 2
fi

currentType=${TEST_TYPE[$type]}

if [ "$currentType" == "${TEST_TYPE[0]}" ];then
  echo ${TEST_TYPE[0]}

elif [ "$currentType" == "${TEST_TYPE[1]}" ];then
  echo ${TEST_TYPE[1]}

elif [ "$currentType" == "${TEST_TYPE[2]}" ];then
  echo ${TEST_TYPE[2]}

elif [ "$currentType" == "${TEST_TYPE[3]}" ];then
  echo ${TEST_TYPE[3]}

elif [ "$currentType" == "${TEST_TYPE[4]}" ];then
  echo ${TEST_TYPE[4]}

elif [ "$currentType" == "${TEST_TYPE[5]}" ];then
  cargo test sort -- --test-threads=1

 fi
