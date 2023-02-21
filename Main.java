

import java.util.*;



        class LL {
            node head;
            int size;

            LL(){
                this.size = 0;
            }
           class node {

               String data;
               LL.node next;

               node(String data) {
                   this.data = data;
                   this.next = null;

                   size++;
               }

           }

           void AddFirst(String data){
               node newNode = new node(data);
               if (head == null){
                   head = newNode;
                   return;
               }
               newNode.next = head;

               head = newNode;


           }

           void AddLast(String  data){
               node newNode = new node(data);
               if (head == null){
                   head = newNode;
                   return;
               }

               node currnode = head;

               while(currnode.next !=null){
                   currnode = currnode.next;
               }

               currnode.next = newNode;

           }

           void PrintList(){
               if (head == null){
                   System.out.println("list is empty");
                   return;
               }


               node currnode = head;

               while(currnode !=null){
                   System.out.print(currnode.data + "->");
                   currnode = currnode.next;
               }

               System.out.println("NULL");




           }

           void RemoveFast(){
               if (head == null){
                   System.out.println("list is empty");
                   return;
               }
               size--;

               head = head.next;

           }

           void RemoveLast(){
               if (head == null){
                   System.out.println("list is empty");
                   return;
               }
               size--;
               if (head.next == null)
               {
                   head = null;
                   return;
               }


               node SecondLast = head;
               node LastNode = head.next;

               while (LastNode.next != null){
                   LastNode = LastNode.next;
                   SecondLast = SecondLast.next;
               }
               SecondLast.next = null;


           }
           int getsizee(){
                return  size;
           }


           public static void main(String[] args) {

               LL list = new LL();

               list.AddFirst("a");
               list.AddFirst("is");
               list.PrintList();
               list.AddLast("fuckboy");
               list.PrintList();
               list.RemoveFast();
               list.PrintList();
               list.RemoveLast();
               list.PrintList();
               System.out.println( list.getsizee());


           }
       }
