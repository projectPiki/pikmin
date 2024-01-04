#ifndef _ZEN_OGSCRFILESELECTMGR_H
#define _ZEN_OGSCRFILESELECTMGR_H

/*
 * @brief TODO
 */
namespace zen {
struct ogScrFileSelectMgr {
	void setOperateMode_Copy();
	void CopyEffectStart();
	void OperateCopy(Controller*);
	void setOperateMode_Delete();
	void OperateDelete(Controller*);
};
} // namespace zen

#endif
