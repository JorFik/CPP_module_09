# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/07 19:39:54 by JFikents          #+#    #+#              #
#    Updated: 2024/09/07 20:25:17 by JFikents         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Compile
make

# Test 1 invalid files
echo "--------------------------Test 1 invalid files--------------------------"
INVALID_FILES=(TransactionBooks/invalid/*)

for file in "${INVALID_FILES[@]}"
do
	./btc "$file"
	echo
done

# Test 2 valid files
echo "---------------------------Test 2 valid files---------------------------"
VALID_FILES=(TransactionBooks/valid/*)
mkdir TransactionOutput 2> /dev/null

for file in "${VALID_FILES[@]}"
do
	(./btc "$file" 2>&1) > TransactionOutput/$(basename $file).out
	echo
	cat TransactionOutput/$(basename $file).out
done

YELLOW='\033[3;33m'
RESET='\033[0m'
echo "$YELLOW All output files are available in TransactionOutput$RESET"

# Test 3 invalid arguments
echo "------------------------Test 3 invalid arguments------------------------"
touch no_permission_file
chmod 000 no_permission_file
INVALID_ARGS=('' "non_existant_file" "no_permission_file")

for arg in "${INVALID_ARGS[@]}"
do
	./btc "$arg"
	echo
done
./btc
chmod 777 no_permission_file
rm no_permission_file
echo

# Test 4 no Database .csv file
echo "----------------------Test 4 no Database .csv file----------------------"
echo Compiling without database
make re NO_DATABASE=1
./btc TransactionBooks/valid/pipe_delimiter
echo

# Test 5 invalid Database
echo "-------------------------Test 5 invalid Database-------------------------"
echo Compiling with invalid database
make re INVALID_DATABASE=1
./btc TransactionBooks/valid/pipe_delimiter
echo
echo Reverting to original database
make re