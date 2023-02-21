#include "StreamAssetLoader.h"
#include <iostream>
#include "TextureManager.h"
#include "StringUtils.h"
#include "IExecutionEvent.h"

StreamAssetLoader::StreamAssetLoader(String path, IExecutionEvent* executionEvent)
{
	this->path = path;
	this->executeEvent = executionEvent;
}

StreamAssetLoader::~StreamAssetLoader()
{
	std::cout << "Destroying stream asset loader. " << std::endl;
}

//void StreamAssetLoader::run()
//{
//	//delay
//	IETThread::sleep(500);
//
//	// from texturemanager
//	std::vector<String> tokens = StringUtils::split(path, '/');
//	String assetName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];
//	TextureManager::getInstance()->instantiateAsTexture(path, assetName, true);
//
//	std::cout << "[TextureManager] Loaded streaming texture: " << assetName << std::endl;
//
//	this->executeEvent->onFinishedExecution();
//	delete this;
//}

void StreamAssetLoader::onStartTask()
{
	//simulate loading of very large file
	IETThread::sleep(1000);

	std::vector<String> tokens = StringUtils::split(path, '/');
	String assetName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];
	TextureManager::getInstance()->instantiateAsTexture(path, assetName, true);

	std::cout << "[TextureManager] Loaded streaming texture: " << assetName << std::endl;

	this->executeEvent->onFinishedExecution();
	//delete after being done
	delete this;
}