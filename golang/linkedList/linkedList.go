package linkedlist

import (
	"errors"
	"fmt"
)

/* Implementacion de lista enlazada con genericos */
type List[E any] interface {
	AddFrist(element E)
	Add(element E)
	RemoveFirst()
	RemoveLast()
	Remove(index int) error
	IsEmpty() bool
	Size() int
	Get(index int) (E, error)
	Print()
}

type node[E any] struct {
	prev    *node[E]
	element E
	next    *node[E]
}

type LinkedList[E any] struct {
	first *node[E]
	size  int
	last  *node[E]
}

func (l *LinkedList[E]) AddFirst(element E) {
	l.linkFirst(l.createNode(element))
}

func (l *LinkedList[E]) Add(element E) {
	l.linkLast(l.createNode(element))
}

func (l *LinkedList[E]) RemoveFirst() {
	if l.first != nil {
		l.unlink(l.first)
	}
}

func (l *LinkedList[E]) RemoveLast() {
	if l.last != nil {
		l.unlink(l.last)
	}
}

func (l *LinkedList[E]) Remove(index int) error {
	n, err := l.node(index)

	if err != nil {
		return fmt.Errorf("can't remove the element: %w", err)
	}

	l.unlink(n)
	return nil
}

func (l *LinkedList[E]) Get(index int) (E, error) {
	n, err := l.node(index)
	if err != nil {
		return n.element, fmt.Errorf("can't remove the element: %w", err)
	}

	return n.element, nil
}

func (l *LinkedList[E]) IsEmpty() bool {
	return l.first == nil
}

func (l *LinkedList[E]) Size() int {
	return l.size
}

func (l *LinkedList[E]) Print() {
	p := l.first
	for p != nil {
		fmt.Printf("%v -> ", p.element)
		p = p.next
	}
	fmt.Println("nil")
}

/* Private Functions */

func (l *LinkedList[E]) node(index int) (*node[E], error) {
	if index < 0 || index >= l.size {
		return nil, errors.New("element not found")
	}

	if l.size == 0 {
		return nil, errors.New("list empty")
	}

	var n *node[E] = nil

	if index < l.size {
		if index < (l.size >> 1) {
			n = l.first
			for i := 0; i < index; i++ {
				n = n.next
			}
		} else {
			n = l.last
			for j := l.size - 1; j > index; j-- {
				n = n.prev
			}
		}
	}

	return n, nil

}

func (l *LinkedList[E]) createNode(element E) *node[E] {
	n := node[E]{
		element: element,
		prev:    nil,
		next:    nil,
	}

	return &n
}

func (l *LinkedList[E]) unlink(n *node[E]) {
	prev := n.prev
	next := n.next

	if prev == nil {
		l.first = next
	} else {
		prev.next = next
		n.prev = nil
	}

	if next == nil {
		l.last = prev
	} else {
		next.prev = prev
		n.next = nil
	}
	n = nil
	l.size--
}

func (l *LinkedList[E]) linkFirst(n *node[E]) {
	if l.first == nil {
		l.first = n
		l.last = n
	} else {
		l.first.prev = n
		n.next = l.first
		l.first = n
	}
	l.size++
}

func (l *LinkedList[E]) linkLast(n *node[E]) {
	if l.last == nil {
		l.first = n
		l.last = n
	} else {
		l.last.next = n
		n.prev = l.last
		l.last = n
	}
	l.size++
}
