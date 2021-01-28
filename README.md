# reader_writer-problem

The readers-writers problem relates to an object such as a file that is shared between multiple processes. Some of these processes are readers i.e. they only want to read the data from the object and some of the processes are writers i.e. they want to write into the object.

The readers-writers problem is used to manage synchronization so that there are no problems with the object data. For example - If two readers access the object at the same time there is no problem. However if two writers or a reader and writer access the object at the same time, there may be problems.

To solve this situation, a writer should get exclusive access to an object i.e. when a writer is accessing the object, no reader or writer may access it. However, multiple readers can access the object at the same time.

This can be implemented using semaphores. 

I have considered two condition :
1. when reader has the priority 
2.When writer has the priority



References :- 
Operating system Concepts- Galvin
http://faculty.cs.niu.edu/~hutchins/csci480/semaphor.htm
https://computing.llnl.gov/tutorials/pthreads/
https://www.educative.io/edpresso/how-to-create-a-simple-thread-in-c

