#ifndef _CONF
#define _CONF

struct range {
	char *start;
	char *end;
	struct range *next;
};

struct options{
	struct range *ip;
	char *dns;
	char *domain_name;
	char *routers;
	char *allow;
	int max_lease_time;
	int def_lease_time;
};

struct subnet{
	struct options* opt;
	struct subnet* next;
	char* subnet_id;
	char* subnet_mask;
};

struct redirect{
	char *uri;
	char *subnet;
	struct redirect *next;
};

struct snat_pool{
	struct range *ip;
	struct snat_pool *next;
	char* pool_name;
};


struct pool_config{
	struct options* opt;
	struct subnet *sub;
	struct subnet *cur_sub;
	struct pool_config* next;
	char* pool_name;
};

struct class_config{
	char *class_name;
	char *rule;
	struct class_config *next;
};


struct nas_config {
	char *nas_ip;
	char *aaa_model;
	char *framed_ip;
	char *qos_policy;
	char *class_policy;
	char *service_policy;
	char *uam_secret;
	char *uam_ip;
	char *service;
	struct redirect *rule;
	int accounting_intvl;
	int idle_timeout;
	int nas_id;
	int uam_port;
};

struct config{
	struct pool_config *dhcp_pool;
	struct class_config *dhcp_class;
	struct snat_pool *snat_pool;
	struct nas_config *nas; 
};

#endif
