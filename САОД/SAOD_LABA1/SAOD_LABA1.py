print("Проверка")

class stek:
    stek_ = [None] * 5;
    def is_empty(stek_):
        if len(stek_) == 0:
            return True
        else:
            return False
    def push_back(stek_, x):
        stek_[-1] = x
    def pop(stek_):
        x = stek_[0]
        stek_[0] = -1
        return x
    def stack_top(stek_):
        return stek_[0]
    

a = stek
#print(a.is_empty(a))
a.push_back(a, 15)
#print(a.is_empty(a))
