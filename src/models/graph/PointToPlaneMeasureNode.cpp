#include "models/graph/PointToPlaneMeasureNode.h"

PointToPlaneMeasureNode::PointToPlaneMeasureNode()
    : AMeasureNode()
{
    setName(TEXT_DEFAULT_NAME_POINT_TO_PLANE.toStdWString());
}

PointToPlaneMeasureNode::PointToPlaneMeasureNode(const PointToPlaneMeasureNode& node)
	: AMeasureNode(node)
	, PointToPlaneMeasureData(node)
{
      /*
    auto* poplm = static_cast<UIPointToPlaneMeasure*>(autoMeasure);
    measurePoints.push_back(PointBufferData(poplm->getPointOnPlane()));
    measurePoints.push_back(PointBufferData(poplm->getProjPoint()));
    measureColors.push_back(0xFFFFFFFF); // white
    measureIds.push_back(poplm->getId());
    measurePoints.push_back(PointBufferData(poplm->getPointCoord()));
    measurePoints.push_back(PointBufferData(poplm->getProjPoint()));
    measureColors.push_back(0xFFFFFFFF); // white
    measureIds.push_back(poplm->getId());
    storedMeasure.insert({ poplm->getId(), poplm->getMeasures() });
    */
}


std::vector<Measure> PointToPlaneMeasureNode::getMeasures() const
{
    return PointToPlaneMeasureData::getMeasures();
}

ElementType PointToPlaneMeasureNode::getType() const
{
    return ElementType::PointToPlaneMeasure;
}

TreeType PointToPlaneMeasureNode::getDefaultTreeType() const
{
    return TreeType::Measures;
}

void PointToPlaneMeasureNode::getSegmentDrawData(const glm::dmat4& gTransfo, std::vector<SegmentDrawData>& segments) const
{
    for (const Measure& measure : PointToPlaneMeasureData::getMeasures())
    {
        glm::dvec4 gOri = gTransfo * glm::dvec4(measure.origin, 1.0);
        glm::dvec4 gFin = gTransfo * glm::dvec4(measure.final, 1.0);
        segments.push_back(SegmentDrawData(
            { gOri.x, gOri.y, gOri.z },
            { gFin.x, gFin.y, gFin.z },
            0xDEAD00FF,
            m_graphicId,
            SHOW_ALL_SEGMENT));
    }
}