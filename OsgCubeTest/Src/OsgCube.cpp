#include <osg\ref_ptr>
#include <osgViewer\Viewer>
#include <osg\Geode>
#include <osg\Group>
#include <osg\Geometry>
#include <iostream>

osg::ref_ptr<osg::Group> CreateCube()
{
	osg::ref_ptr<osg::Group> cubeGroup = new osg::Group;
	osg::ref_ptr<osg::Geode> cubeGeode = new osg::Geode;
	osg::ref_ptr<osg::Geometry> cubeGeometry = new osg::Geometry;

	cubeGroup->addChild(cubeGeode.get());
	cubeGeode->addDrawable(cubeGeometry.get());

	osg::ref_ptr<osg::Vec3Array> _vertArray = new osg::Vec3Array;
	// Side faces
	_vertArray->push_back(osg::Vec3(-1.0, -1.0, 1.0));
	_vertArray->push_back(osg::Vec3(-1.0, -1.0, -1.0));
	_vertArray->push_back(osg::Vec3(1.0, -1.0, 1.0));
	_vertArray->push_back(osg::Vec3(1.0, -1.0, -1.0));
	_vertArray->push_back(osg::Vec3(1.0, 1.0, 1.0));
	_vertArray->push_back(osg::Vec3(1.0, 1.0, -1.0));
	_vertArray->push_back(osg::Vec3(-1.0, 1.0, 1.0));
	_vertArray->push_back(osg::Vec3(-1.0, 1.0, -1.0));
	_vertArray->push_back(osg::Vec3(-1.0, -1.0, 1.0));
	_vertArray->push_back(osg::Vec3(-1.0, -1.0, -1.0));

	// batch
	_vertArray->push_back(osg::Vec3(-1.0, -1.0, -1.0));
	_vertArray->push_back(osg::Vec3(-1.0, 1.0, 1.0));

	//top
	_vertArray->push_back(osg::Vec3(-1.0, 1.0, 1.0));
	_vertArray->push_back(osg::Vec3(-1.0, -1.0, 1.0)); 
	_vertArray->push_back(osg::Vec3(1.0, 1.0, 1.0));
	_vertArray->push_back(osg::Vec3(1.0, -1.0, 1.0));

	//batch
	_vertArray->push_back(osg::Vec3(1.0, -1.0, 1.0));
	_vertArray->push_back(osg::Vec3(-1.0, -1.0, -1.0));

	//bottom
	_vertArray->push_back(osg::Vec3(-1.0, -1.0, -1.0));
	_vertArray->push_back(osg::Vec3(-1.0, 1.0, -1.0));
	_vertArray->push_back(osg::Vec3(1.0, -1.0, -1.0));
	_vertArray->push_back(osg::Vec3(1.0, 1.0, -1.0));


	osg::ref_ptr<osg::Vec4Array> _colorArray = new osg::Vec4Array;
	// side faces
	_colorArray->push_back(osg::Vec4(0.0, 1.0, 1.0, 1.0));
	_colorArray->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));
	_colorArray->push_back(osg::Vec4(1.0, 1.0, 1.0, 1.0));
	_colorArray->push_back(osg::Vec4(1.0, 1.0, 0.0, 1.0));
	_colorArray->push_back(osg::Vec4(1.0, 0.0, 1.0, 1.0));
	_colorArray->push_back(osg::Vec4(1.0, 0.0, 0.0, 1.0));
	_colorArray->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));
	_colorArray->push_back(osg::Vec4(0.0, 0.0, 0.0, 1.0));
	_colorArray->push_back(osg::Vec4(0.0, 1.0, 1.0, 1.0));
	_colorArray->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));

	//batch
	_colorArray->push_back(osg::Vec4(0.0, 1.0, 0.0, 1.0));
	_colorArray->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));

	//top
	_colorArray->push_back(osg::Vec4(0.0, 0.0, 1.0, 1.0));
	_colorArray->push_back(osg::Vec4(0.0, 1.0, 1.0, 1.0));
	_colorArray->push_back(osg::Vec4(1.0, 0.0, 1.0, 1.0));
	_colorArray->push_back(osg::Vec4(1.0, 1.0, 1.0, 1.0));

	//batch
	_colorArray->push_back(osg::Vec4(1.0, 1.0, 1.0, 1.0));
	_colorArray->push_back(osg::Vec4(0.0, 1.0, 0.0, 0.0));

	//bottom
	_colorArray->push_back(osg::Vec4(0.0, 1.0, 0.0, 0.0));
	_colorArray->push_back(osg::Vec4(0.0, 0.0, 0.0, 0.0));
	_colorArray->push_back(osg::Vec4(1.0, 1.0, 0.0, 0.0));
	_colorArray->push_back(osg::Vec4(1.0, 0.0, 0.0, 0.0));


	cubeGeometry->setVertexArray(_vertArray.get());
	cubeGeometry->setColorArray(_colorArray.get());

	cubeGeometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

	cubeGeometry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::TRIANGLE_STRIP, 0, _vertArray->size()));

	cubeGroup->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);

	return(cubeGroup.release());
}

void main()
{
	osgViewer::Viewer _viewer;
	
	osg::ref_ptr<osg::Group> root = CreateCube();
	
	_viewer.setSceneData(root.get());
	
	_viewer.run();
}
