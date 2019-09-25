use test;

SELECT DISTINCT groupp.name, worker.fio,  rolle.role_name, worker_place.ST_Date
FROM worker_place
LEFT JOIN worker ON worker.id = worker_place.ID_worker
LEFT JOIN groupp ON groupp.id = worker_place.ID_groupp
LEFT JOIN rolle ON rolle.ID = worker.ID_role
ORDER BY groupp.name;
