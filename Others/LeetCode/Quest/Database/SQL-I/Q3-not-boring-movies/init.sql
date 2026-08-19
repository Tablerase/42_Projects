create table if not exists cinema (id int, movie varchar(255), description varchar(255), rating numeric(2, 1));
truncate table cinema;
insert into cinema (id, movie, description, rating) values ('1', 'war', 'great 3d', '8.9');
insert into cinema (id, movie, description, rating) values ('2', 'science', 'fiction', '8.5');
insert into cinema (id, movie, description, rating) values ('3', 'irish', 'boring', '6.2');
insert into cinema (id, movie, description, rating) values ('4', 'ice song', 'fantacy', '8.6');
insert into cinema (id, movie, description, rating) values ('5', 'house card', 'interesting', '9.1');
