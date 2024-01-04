package main

import (
	"fmt"
	linkedlist "golang/linkedList"
)

func main() {
	fmt.Println("Hola Mundo")

	arrayList := new(linkedlist.LinkedList[string])

	arrayList.Add("sting")
	arrayList.Add("Sofía")
	arrayList.Add("Alberto")
	arrayList.Print()

	n, err := arrayList.Get(2)

	if err != nil {
		fmt.Printf("Error: %s\n", err)
		return
	}
	fmt.Printf("Elemento encontrado: %s\n", n)
}
