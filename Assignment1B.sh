# Write a program to implement an address book with options given below: a) Create address
# book. b) View address book. c) Insert a record. d) Delete a record. e) Modify a record. f) Exit

#!/bin/bash

BOOK="book.txt"

exit=0

while [ $exit -ne 1 ]
do
    echo "-------------------------------------"
    echo "What operation do you want?"
    echo -e "\n1 Insert a record \n2.View Address Book \n3.Search Address Book \n4.Delete record \n5.Modify a record \n6.Exit \n\nEnter your choice: "
    read answer
    echo "-------------------------------------"
    
    if [ "$answer" = 1 ]
    then
        # Entries into file
	echo -e "\nWelcome to Address Book..."
	echo -n "Name of person: "
	read name

	echo -n "Phone number: "
	read phone

	echo "Should I enter the values:"
	echo -e "$name ; $phone \n"
	echo -n "y/n: "
	read answer

	if [ "$answer" == "y" ]
	then
 	   echo "$name ; $phone" >>$BOOK
	else 
           echo -e "$name ; $phone \nNOT written to $BOOK"
	fi

	# exit 0
    elif [ "$answer" = 2 ]
    then 
        # Reading of file

	echo "Name ; Phone Number"

	cat "book.txt"
    elif [ "$answer" = 3 ]
    then 
        # search a record into file

	echo -n "Enter the name of person you are looking for: "
	read find

	echo "Name ; Phone number"
	grep -i $find $BOOK
    elif [ "$answer" = 4 ]
    then 
        # delete record from file

	BOOK="book.txt"

	cat "book.txt"

	echo -n "Enter name to delete record: "
	read line

	grep -v "$line" $BOOK > tmp.txt && mv tmp.txt $BOOK
	echo -e "\n***** AddressBook *****"
	cat "book.txt"
	echo -e "\nRecord deleted successfully..."
    elif [ "$answer" = 5 ]
    then 
	# modify a record
	Book="book.txt"
	echo -e "Modify record\nEnter Name/Phone Number"
	read pattern
	temp="temp"
	grep -v $pattern $Book | cat >> $temp
	rm $Book
	cat $temp | cat >> $Book
	rm $temp
	echo -e "\nEnter name: "
	read name
	echo -e "\nEnter Phone Number of $name : "
	read number
	echo -e "\n$name ; $number" | cat >> $Book
    elif [ "$answer" = 6 ]
    then 
        exit=1
    else
        echo "Wrong input"
    fi
done

exit 0
