import heapq

def astar(graph,start_node,end_node):
   f_distance={node:float('inf') for node in graph}
   f_distance[start_node]=0
  
   g_distance={node:float('inf') for node in graph}
   g_distance[start_node]=0
  
   came_from={node:None for node in graph}
   came_from[start_node]=start_node
  
   queue=[(0,start_node)]
   while queue:

       current_f_distance, current_node = heapq.heappop(queue)

       if current_node == end_node:
           return f_distance, came_from

       for next_node,weights in graph[current_node].items():
           temp_g_distance = g_distance[current_node] + weights[0]
          
           if temp_g_distance<g_distance[next_node]:
               g_distance[next_node]=temp_g_distance
               heuristic=weights[1]
               f_distance[next_node]=temp_g_distance+heuristic
               came_from[next_node]=current_node
              
               heapq.heappush(queue, (f_distance[next_node], next_node))
              
   return f_distance, came_from


if __name__ == "__main__":
   # node: [weight, h(n)]
   graph = {
       'A':{'B':[6,8],'F':[3,6]},
       'B':{'C':[3,5],'D':[2,7]},
       'C':{'D':[1,7], 'E':[5,3]},
       'D':{'E': [8,3]},
       'E':{'I':[5,1], 'J':[5,0]},
       'F':{'G':[1,5], 'H':[7,3]},
       'G':{'I':[3,1]},
       'H':{'I':[2,1]},
       'I':{'J': [3, 0]},
       'J':{}
   }

   start_node = 'A'
   end_node = 'J'

   ret = astar(graph, start_node, end_node)

   path = [end_node]
   cur_node = end_node
   while cur_node != start_node:
       cur_node = ret[1][cur_node]
       path.append(cur_node)

   path.reverse()

   print("Path: ", path)