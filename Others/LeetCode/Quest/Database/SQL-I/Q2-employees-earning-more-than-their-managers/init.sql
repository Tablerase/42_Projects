create table if not exists employee (id int, name varchar(255), salary int, managerid int);
truncate table employee;
insert into employee (id, name, salary, managerid) values ('1', 'joe', '70000', '3');
insert into employee (id, name, salary, managerid) values ('2', 'henry', '80000', '4');
insert into employee (id, name, salary, managerid) values ('3', 'sam', '60000', null);
insert into employee (id, name, salary, managerid) values ('4', 'max', '90000', null);
