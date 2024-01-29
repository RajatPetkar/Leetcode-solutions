SELECT Person.firstName, Person.lastName, 
       IFNULL(Address.city, null) AS city, 
       IFNULL(Address.state, null) AS state
FROM Person
LEFT JOIN Address ON Person.personId = Address.personId;
