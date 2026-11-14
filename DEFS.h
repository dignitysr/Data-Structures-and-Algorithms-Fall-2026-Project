#pragma once
enum CarStatus {
    STATUS_IDLE,
    STATUS_ERLY,
    STATUS_LATE,
    STATUS_REDY,
    STATUS_DIAG,
    STATUS_WAIT,
    STATUS_SERV,
    STATUS_CNCL,
    STATUS_FNSH
};

enum ServiceType {
    TYPE_MU,
    TYPE_EU,
    TYPE_WU
};

// Sequence Type
enum SequenceType {
   SS,
   FS
};
enum BayType {
    DU,
    MU,
    EU,
    WU
};