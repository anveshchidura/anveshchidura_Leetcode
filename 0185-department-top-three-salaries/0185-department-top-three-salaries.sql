# Write your MySQL query statement below

select Department,Employee,Salary from
(
    select *,DENSE_RANK() over (partition by Department order by Salary desc) as ind from
    (
        select * from
        (
            select dep.name as Department, emp.name as Employee, emp.salary as Salary
            from  Employee emp 
            left join 
            Department dep
            on emp.departmentId = dep.id
        ) as A1
        order by Department
    ) as A2

) as A3
where ind < 4;