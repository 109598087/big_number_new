import ttg


def t_t(number):
    list1 = list()
    for i in range(number):
        list1.append(str(i))
    table = ttg.Truths(list1)
    list2 = table.as_pandas().values.tolist()
    return list2


num = 3
list3 = t_t(num)
print(list3)
for i in range(len(list3)):
    for j in range(len(list3[i])):
        print(list3[i][j])
        print(bool(list3[i][j]))
