


def selectionSt(array, size):
   
    for step in range(size):
        min_id = step

        for p in range(step + 1, size):
         
            
            if array[p] < array[min_id]:
                min_id = p
         
        
        (array[step], array[min_id]) = (array[min_id], array[step])


data = [-34, -10, -7, 15, -88]
size = len(data)
selectionSt(data, size)
print('Sorted Array in Ascending Order:')
print(data)
