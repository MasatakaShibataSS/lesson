a = 0

def funcB():

    b = 1
   
    print("funcBのなかでは変数aと変数bが使えます。")
    print("変数aの値は", a, "です。")
    print("変数bの値は", b, "です。")
    #print("変数cの値は", c, "です。")

def funcC():

    c = 2
   
    print("funcCのなかでは変数aと変数cが使えます。")
    print("変数aの値は", a, "です。")
    #print("変数bの値は", b, "です。")
    print("変数cの値は", c, "です。")


print("関数の外で変数aが使えます。")
print("変数aの値は", a, "です。")
#print("変数bの値は", b, "です。")
#print("変数cの値は", c, "です。")

funcB()
funcC()
