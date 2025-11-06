# King-of-the-Hill


make file immunable:

>gcc -O2 -Wall immut.c -o immut

>./immut +i /root/king.txt  

>lsattr /root/king.txt    # უნდა ჩანდეს i ფლაგი

ფაილი გახადეთ მხოლოდ წაკითხვისთვის (immutable), რაც უზრუნველყოფს მის დაცვას მოდიფიკაციისა და წაშლისგან root-ის ჩათვლით.
