The servers consist of front end servers and mid tier servers. The front ends’ responsibility is to get requests from clients and put them in a queue. The first VM which is VM 0, The middle servers’ responsibility is to retrieve requests from the queue and process those requests. The master server acts as a front end as well but is primarily responsible for scaling in, scaling out, and initiating middle and front servers. 
	In order to know how many middle tier and front end servers to start initially, I calculated the interarrival time. This computation is done by the master server. The interarrival rate was calculated by measuring the amount of requests that are added to the queue of requests in a certain time interval. It was also important to make sure that the master received and processed requests during this time interval so that clients would be served. Additionally, the master server continued to receive requests and queue those requests in the time that the initial middle tier servers were booting. 
	After initializing the front and middle servers, the master’s job is to constantly compute the interarrival rate and add or remove servers according to the newly computed interarrival rates; greater interarrival times would require less front and middle tier servers while smaller interarrival times would require more. The new interarrival times were calculated using client arrival rate along with requests in the master server’s request queue. After computing the interarrival rate, the master server calculates the ideal number of middle tier and front end VMs to start. These numbers were calculated using data that I collected from testing on constant inter arrival rates. The master then takes the difference in ideal number of VMs between iterations and adds or removes VMs. 
	I used several data structures to keep track of servers, requests, and other information. I used an ArrayBlockingQueue to keep track of requests that are queued up by front end servers so that middle tier servers can retrieve requests. In the case that the ArrayBlockingQueue is full, subsequent requests were dropped. I used a concurrent hashmap to map VMid to the type of VM (either front or middle). I used two linked lists to keep track of front end and mid tier VM’s by their VMid. 
	Another important feature was implementing remote methods so that servers would be able to communicate with each other. For example, when a front end VM is booted, in order to add to the linked list of frontend VMids which are in the master, it must call a remote method. For this to work properly, I had to bind every instance of a new server to the VMid so that those VMid’s can be used to look up the corresponding server and make RPC calls.
