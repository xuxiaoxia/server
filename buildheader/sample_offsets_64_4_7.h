/* BDB offsets on a 64-bit machine */
#define DB_VERSION_MAJOR_64 4
#define DB_VERSION_MINOR_64 7
#define DB_VERSION_STRING_64 "Berkeley DB Compatability Header 4.7"
struct fieldinfo db_btree_stat_fields64[] = {
  {"u_int32_t bt_nkeys", 12, 4},
  {"u_int32_t bt_ndata", 16, 4},
  {0, 84, 84} /* size of whole struct */
};
struct fieldinfo db_env_fields64[] = {
  {"void *app_private", 216, 8},
  {"void *api1_internal", 224, 8},
  {"int  (*close) (DB_ENV *, u_int32_t)", 408, 8},
  {"void (*err) (const DB_ENV *, int, const char *, ...)", 432, 8},
  {"int (*get_cachesize) (DB_ENV *, u_int32_t *, u_int32_t *, int *)", 472, 8},
  {"int (*get_flags) (DB_ENV *, u_int32_t *)", 520, 8},
  {"int  (*get_lg_max) (DB_ENV *, u_int32_t*)", 568, 8},
  {"int  (*get_lk_max_locks) (DB_ENV *, u_int32_t *)", 608, 8},
  {"int  (*log_archive) (DB_ENV *, char **[], u_int32_t)", 800, 8},
  {"int  (*log_flush) (DB_ENV *, const DB_LSN *)", 824, 8},
  {"int  (*open) (DB_ENV *, const char *, u_int32_t, int)", 1048, 8},
  {"int  (*set_cachesize) (DB_ENV *, u_int32_t, u_int32_t, int)", 1328, 8},
  {"int  (*set_data_dir) (DB_ENV *, const char *)", 1336, 8},
  {"void (*set_errcall) (DB_ENV *, void (*)(const DB_ENV *, const char *, const char *))", 1352, 8},
  {"void (*set_errfile) (DB_ENV *, FILE*)", 1360, 8},
  {"void (*set_errpfx) (DB_ENV *, const char *)", 1368, 8},
  {"int  (*set_flags) (DB_ENV *, u_int32_t, int)", 1392, 8},
  {"int  (*set_lg_bsize) (DB_ENV *, u_int32_t)", 1416, 8},
  {"int  (*set_lg_dir) (DB_ENV *, const char *)", 1424, 8},
  {"int  (*set_lg_max) (DB_ENV *, u_int32_t)", 1440, 8},
  {"int  (*set_lk_detect) (DB_ENV *, u_int32_t)", 1464, 8},
  {"int  (*set_lk_max_locks) (DB_ENV *, u_int32_t)", 1480, 8},
  {"int  (*set_tmp_dir) (DB_ENV *, const char *)", 1600, 8},
  {"int  (*set_verbose) (DB_ENV *, u_int32_t, int)", 1624, 8},
  {"int  (*txn_begin) (DB_ENV *, DB_TXN *, DB_TXN **, u_int32_t)", 1640, 8},
  {"int  (*txn_checkpoint) (DB_ENV *, u_int32_t, u_int32_t, u_int32_t)", 1648, 8},
  {"int  (*txn_stat) (DB_ENV *, DB_TXN_STAT **, u_int32_t)", 1664, 8},
  {0, 1688, 1688} /* size of whole struct */
};
struct fieldinfo db_key_range_fields64[] = {
  {"double less", 0, 8},
  {"double equal", 8, 8},
  {"double greater", 16, 8},
  {0, 1688, 1688} /* size of whole struct */
};
struct fieldinfo db_lsn_fields64[] = {
  {0, 8, 8} /* size of whole struct */
};
struct fieldinfo db_fields64[] = {
  {"void *app_private", 32, 8},
  {"DB_ENV *dbenv", 40, 8},
  {"void *api_internal", 488, 8},
  {"int (*close) (DB*, u_int32_t)", 544, 8},
  {"int (*cursor) (DB *, DB_TXN *, DBC **, u_int32_t)", 560, 8},
  {"int (*del) (DB *, DB_TXN *, DBT *, u_int32_t)", 568, 8},
  {"int (*fd) (DB *, int *)", 600, 8},
  {"int (*get) (DB *, DB_TXN *, DBT *, DBT *, u_int32_t)", 608, 8},
  {"int (*get_flags) (DB *, u_int32_t *)", 688, 8},
  {"int (*get_pagesize) (DB *, u_int32_t *)", 752, 8},
  {"int (*key_range) (DB *, DB_TXN *, DBT *, DB_KEY_RANGE *, u_int32_t)", 832, 8},
  {"int (*open) (DB *, DB_TXN *, const char *, const char *, DBTYPE, u_int32_t, int)", 840, 8},
  {"int (*put) (DB *, DB_TXN *, DBT *, DBT *, u_int32_t)", 856, 8},
  {"int (*remove) (DB *, const char *, const char *, u_int32_t)", 864, 8},
  {"int (*rename) (DB *, const char *, const char *, const char *, u_int32_t)", 872, 8},
  {"int (*set_bt_compare) (DB *, int (*)(DB *, const DBT *, const DBT *))", 896, 8},
  {"int (*set_dup_compare) (DB *, int (*)(DB *, const DBT *, const DBT *))", 928, 8},
  {"void (*set_errfile) (DB *, FILE*)", 952, 8},
  {"int (*set_flags) (DB *, u_int32_t)", 976, 8},
  {"int (*set_pagesize) (DB *, u_int32_t)", 1040, 8},
  {"int (*stat) (DB *, void *, u_int32_t)", 1104, 8},
  {"int (*truncate) (DB *, DB_TXN *, u_int32_t *, u_int32_t)", 1128, 8},
  {"int (*verify) (DB *, const char *, const char *, FILE *, u_int32_t)", 1144, 8},
  {0, 1208, 1208} /* size of whole struct */
};
struct fieldinfo db_txn_active_fields64[] = {
  {"u_int32_t txnid", 0, 4},
  {"DB_LSN lsn", 24, 8},
  {0, 232, 232} /* size of whole struct */
};
struct fieldinfo db_txn_fields64[] = {
  {"DB_ENV *mgrp /*In TokuDB, mgrp is a DB_ENV not a DB_TXNMGR*/", 0, 8},
  {"DB_TXN *parent", 8, 8},
  {"void *api_internal", 176, 8},
  {"int (*abort) (DB_TXN *)", 200, 8},
  {"int (*commit) (DB_TXN*, u_int32_t)", 208, 8},
  {"u_int32_t (*id) (DB_TXN *)", 232, 8},
  {0, 280, 280} /* size of whole struct */
};
struct fieldinfo db_txn_stat_fields64[] = {
  {"u_int32_t st_nactive", 44, 4},
  {"DB_TXN_ACTIVE *st_txnarray", 64, 8},
  {0, 88, 88} /* size of whole struct */
};
struct fieldinfo dbc_fields64[] = {
  {"DB *dbp", 0, 8},
  {"int (*c_close) (DBC *)", 408, 8},
  {"int (*c_count) (DBC *, db_recno_t *, u_int32_t)", 416, 8},
  {"int (*c_del) (DBC *, u_int32_t)", 424, 8},
  {"int (*c_get) (DBC *, DBT *, DBT *, u_int32_t)", 440, 8},
  {0, 528, 528} /* size of whole struct */
};
struct fieldinfo dbt_fields64[] = {
  {"void*data", 0, 8},
  {"u_int32_t size", 8, 4},
  {"u_int32_t ulen", 12, 4},
  {"u_int32_t flags", 32, 4},
  {0, 40, 40} /* size of whole struct */
};