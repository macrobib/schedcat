#ifndef BLOCKING_H
#define BLOCKING_H

typedef std::vector<const RequestBound*> ContentionSet;
typedef std::vector<ContentionSet> Resources;
typedef std::vector<Resources> ClusterResources;
typedef std::vector<ContentionSet> AllPerCluster;
typedef std::vector<ContentionSet> TaskContention;
typedef std::vector<TaskContention> ClusterContention;

struct LimitedRequestBound {
	LimitedRequestBound(const RequestBound *rqb, unsigned int l) :
		request_bound(rqb), limit(l) {};
	LimitedRequestBound() : request_bound(NULL), limit(0) {};

	const RequestBound  *request_bound;
	unsigned int        limit;
};

typedef std::vector<LimitedRequestBound> LimitedContentionSet;

void sort_by_request_length(LimitedContentionSet &lcs);
void sort_by_request_length(Resources& resources);
void sort_by_request_length(ClusterResources& resources);
void sort_by_request_length(ContentionSet& cs);


typedef std::vector<const TaskInfo*> Cluster;
typedef std::vector<Cluster> Clusters;

void split_by_cluster(const ResourceSharingInfo& info, Clusters& clusters);
void split_by_resource(const ResourceSharingInfo& info, Resources& resources);
void split_by_resource(const Cluster& cluster, Resources& resources);
void split_by_resource(const Clusters& clusters, ClusterResources& resources);


Interference bound_blocking(const ContentionSet& cont,
			    unsigned long interval,
			    unsigned int max_total_requests,
			    unsigned int max_requests_per_source,
			    const TaskInfo* exclude_tsk,
			    unsigned int min_priority = 0);


extern const unsigned int UNLIMITED;

#endif