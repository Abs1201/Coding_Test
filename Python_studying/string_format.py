# % operator (오래된 방식)

test = 'hello %s' % 'bob'


test2 = 'age: %i' % 111

test5 = 'hi i\'m %s and i\'m %i years old' %('jack', 23)


first_name = 'Eric'
last_name = 'Idle'
age = 74
profession = 'comedian'
affiliation = 'ttt'
affiliation = 'Monty Python' 'Hello, %s %s. You are %s. You are a %s. You were a member of %s.' % (first_name, last_name, age, profession, affiliation)

# str.format

test3 = 'hello {}' .format('bob')
test4 = 'hi i\'m {a} and i\'m {b} years old'.format(a='jack', b= 24)

test5 = 'hi i\'m {0} and i\'m {1} years old'.format('jack', 24)


# f-string
name = 'bob'
test6 = f'hello {name}'


if __name__ == '__main__':
    print(test6)

